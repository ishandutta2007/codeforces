#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m,s[1000005];
int ch[1000005],sum[1000005],chp[1000005],sump[1000005],book[1000005];
struct node{
	int l,r; 
}a[1000005];
inline int erfen(int x){
	int l=1,r=m,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
inline int askp(int l,int r){
	return sump[r]-sump[l-1];
}
inline int ask(int l,int r){
	if (ch[l]==1&&ch[l-1]==1)return sum[r]-sum[l-1]+1;
	else return sum[r]-sum[l-1];
}
int main(){
//	freopen("1285E.in","r",stdin);
//	freopen("1285E.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n*2;
		for (int i=1;i<=n;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
			s[i*2-1]=a[i].l,s[i*2]=a[i].r;
		}
		sort(s+1,s+1+m);
		for (int i=1;i<=n;i++){
			a[i].l=erfen(a[i].l);
			a[i].r=erfen(a[i].r);
		}
		for (int i=0;i<=m+5;i++)
			ch[i]=sum[i]=chp[i]=sump[i]=book[i]=0;
		for (int i=1;i<=n;i++){
			if (a[i].l==a[i].r)book[a[i].l]++;
			if (a[i].l!=a[i].r)ch[a[i].l]++,ch[a[i].r]--;
			if (a[i].l!=a[i].r)chp[a[i].l]++,chp[a[i].r+1]--;
		}
		for (int i=1;i<=m+5;i++)
			ch[i]+=ch[i-1],chp[i]+=chp[i-1];
		int res=0,ans=0;
		for (int i=1;i<=m;i++){
			sump[i]=sump[i-1];
			if (book[i]>=1){
				if (chp[i]==0)res++;
				if (chp[i]==1)sump[i]++;
			}
		}
		for (int i=1;i<=m;i++){
			if (ch[i]!=0&&ch[i-1]==0)res++;
		}
		for (int i=1;i<=m;i++){
			sum[i]=sum[i-1];
			if (ch[i]==1&&ch[i-1]!=1)sum[i]++;
		}
		for (int i=1;i<=n;i++){
			int tmp=res;
			if (a[i].l!=a[i].r){
				tmp+=ask(a[i].l,a[i].r-1);
				tmp+=askp(a[i].l,a[i].r);
				if (ch[a[i].l-1]==0&&ch[a[i].l]==1)tmp--;
				if (ch[a[i].r]==0&&ch[a[i].r-1]==1)tmp--;
			}
			else{
				if (book[a[i].l]==1)tmp--;
			}
			ans=max(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}