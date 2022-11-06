#include<bits/stdc++.h>
#define N 200005
#define mod 998244353
using namespace std;
char s[N][62];
struct node{
	int id;
	long long val;
	bool operator<(const node z)const{
		return val<z.val;
	}
}a[200002];
bool bo[62];
long long A[N];
int stac[17],cnt=0,sum[1<<18],Ans[62]={0},o[1<<15],num[1<<17];
int main(){
	int n,m,p,i,j,k,t;
	bool flg=0;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<(1<<15);++i)o[i]=o[i>>1]+(i&1);
	for(i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(j=1;j<=m;++j)s[i][j]-='0';
		a[i].id=i;
		if(i==1)a[i].val=rand();
		else a[i].val=(a[i-1].val*a[i-1].val+107LL)%mod;
	}
	sort(a+1,a+1+n);
	for(j=1;j<=m;++j){
		t=0;
		for(i=1;i<=n;++i)t+=s[i][j];
		if(t*2<n)for(i=1;i<=n;++i)s[i][j]=0;
		else{
			bo[j]=1;
			flg=1;
		}
	}
	if(!flg){
		for(i=1;i<=m;++i)putchar('0');
		return 0;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			A[i]=A[i]+(1LL<<(long long)(j-1))*(long long)s[i][j];
		}
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(i=1;i<=min(20,n);++i){
		int nw=a[i].id;
		cnt=0;
		for(j=1;j<=m;++j)if(s[nw][j])stac[++cnt]=j;
		for(j=0;j<(1<<cnt);++j)sum[j]=num[j]=0;
		for(j=1;j<=n;++j){
			int S1=0;
			for(k=1;k<=cnt;++k)if(s[j][stac[k]])S1|=(1<<(k-1));
			++sum[S1]; 
		}
		for(j=1;j<(1<<cnt);++j){
			for(k=j;k;k=(k-1)&j)num[k]+=sum[j];
		}
		for(j=1;j<(1<<cnt);++j){
			if(num[j]*2>=n&&o[j]>ans){
				ans=o[j];
				for(int l=1;l<=m;++l)Ans[l]=0;
				for(int l=1;l<=cnt;++l)if(j&(1<<(l-1)))Ans[stac[l]]=1;
			}
		}
	}
	for(j=1;j<=m;++j)printf("%d",Ans[j]);puts("");
	return 0;
}