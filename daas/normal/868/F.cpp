#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,ton[MAXN],a[MAXN],lim,rim;
ll dp[21][MAXN],del;
void solve(int l,int r,int L,int R,int k)
{
	if(l>r) return;
	int mid=(l+r)>>1;
	int st=min(mid,R+1);
	while(rim<mid) ++rim,del+=ton[a[rim]],++ton[a[rim]];
	while(lim>st) --lim,del+=ton[a[lim]],++ton[a[lim]];
	while(rim>mid) --ton[a[rim]],del-=ton[a[rim]],--rim;
	while(lim<st) --ton[a[lim]],del-=ton[a[lim]],++lim;
	int minid=-1;
	//cout<<"?? "<<lim<<" "<<rim<<" "<<del<<"||";
	for(int i=st;i>L;--i)
	{
		if(dp[k-1][i-1]+del<dp[k][mid])
		{
			dp[k][mid]=dp[k-1][i-1]+del;
			minid=i-1;
		}
		--lim,del+=ton[a[lim]],++ton[a[lim]];
	}
	//cout<<l<<" "<<r<<" "<<L<<" "<<R<<"||"<<mid<<" "<<minid<<" "<<dp[k][mid]<<endl;
	solve(l,mid-1,L,minid,k);
	solve(mid+1,r,minid,R,k);
}
int main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=K;++i)
	{
		memset(ton,0,sizeof(ton));
		lim=rim=1;
		ton[a[1]]=1;
		del=0;
		solve(1,n,0,n-1,i);
		//cout<<endl;
	}
	printf("%lld\n",dp[K][n]);
	return 0;
}
//ore no turn,draw!