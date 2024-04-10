#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
char c[100005];
int n,rk[100005],sa[100005],sa_[100005],rk_[100005],m=122,lcp[100005],h[100005];
int num[100005],cur[100005],K;
bool cmp(int a,int b){
	if(rk[a]<rk[b])return 1;
	if(a+K>n&&b+K>n)return 0;
	if(a+K>n)return 1;
	return rk[a+K]<rk[b+K];
}
int a[100005],ans[100005];
int main(){
	scanf("%s",c+1),n=strlen(c+1);
	if(n>1){
		for(int i=1;i<=n;i++)rk[i]=c[i];
		for(int i=1;i<=n;i++)num[rk[i]]++;
		for(int i=1;i<=m;i++)cur[i]=cur[i-1]+num[i-1];
		for(int i=1;i<=n;i++)sa[++cur[rk[i]]]=i;
		for(K=1;K<n;K<<=1){
			for(int i=1;i<=m;i++)num[i]=0;
			for(int i=1;i<=n;i++)num[rk[i]]++;
			for(int i=1;i<=m;i++)cur[i]=cur[i-1]+num[i-1];
			for(int i=n-K+1;i<=n;i++)sa_[++cur[rk[i]]]=i;
			for(int i=1;i<=n;i++){
				int p=sa[i];
				if(p-K<1)continue;
				sa_[++cur[rk[p-K]]]=p-K;
			}
			for(int i=1;i<=n;i++)sa[i]=sa_[i],rk_[sa[i]]=rk_[sa[i-1]]+cmp(sa[i-1],sa[i]);
			m=rk_[sa[n]];
			for(int i=1;i<=n;i++)rk[i]=rk_[i];
		}
		for(int i=1;i<=n;i++){
			if(rk[i]==1)lcp[rk[i]]=0;
			else{
				lcp[rk[i]]=max(lcp[rk[i-1]]-1,1);
				while(max(i,sa[rk[i]-1])+lcp[rk[i]]-1<=n&&c[i+lcp[rk[i]]-1]==c[sa[rk[i]-1]+lcp[rk[i]]-1])lcp[rk[i]]++;
				lcp[rk[i]]--;
			}
		}
	}else sa[1]=1,rk[1]=1;
	int lg=n,p=rk[1];
	a[n]=1,h[p]=n;
	for(int i=p-1;i>0;i--){
		lg=min(lg,lcp[i+1]);
		h[i]=lg;
		a[lg]++;
	}
	lg=n;
	for(int i=p+1;i<=n;i++){
		lg=min(lg,lcp[i]);
		h[i]=lg;
		a[lg]++;
	}
	for(int i=n-1;i>=1;i--)a[i]+=a[i+1];
	int res=0;
	for(int i=1;i<=n;i++)
		if(n-sa[i]+1==h[i])
			res++,ans[n-sa[i]+1]=a[h[i]];
	write(res);puts(""); 
	for(int i=1;i<=n;i++)if(ans[i]>0)write(i),putchar(' '),write(ans[i]),puts("");
}