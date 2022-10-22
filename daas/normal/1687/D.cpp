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
const int MAXN=1e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,a[MAXN],pre[MAXN*2],suf[MAXN*2];
ll ans=-1;
void solve(ll l,ll r,int w)
{
	ll lans=l-a[1],rans=r-a[1];
	int las=0;
	for(int i=0;i<=a[n]/w;++i) if((ll)(w+i)*(w+i)-r<=2000000)
	{
		int L=suf[max(0ll,(ll)(w+i)*(w+i)-r)];
		int R=pre[min(2000000ll,(ll)(w+i)*(w+i)+(w+i)-l)];
		if(L!=-1 && R!=-1 && L<=R)
		{
			if(L!=las+1) return;
			las=R;
			lans=max(lans,max(l+a[L]-a[1],(ll)(w+i)*(w+i))-a[L]);
			rans=min(rans,min(r+a[R]-a[1],(ll)(w+i)*(w+i)+(w+i))-a[R]);
		}
	}
	if(las!=n) return;
	if(lans<=rans) ans=lans;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	n=unique(a+1,a+n+1)-a-1;
	memset(pre,-1,sizeof(pre));
	memset(suf,-1,sizeof(suf));
	for(int i=1;i<=n;++i) pre[a[i]-a[1]]=suf[a[i]-a[1]]=i;
	for(int i=1;i<=2000000;++i) if(pre[i]==-1) pre[i]=pre[i-1];
	for(int i=2000000;i>=0;--i) if(suf[i]==-1) suf[i]=suf[i+1];
	for(int w=1;w<=a[n] && ans==-1;++w)
	{
		ll l=max((ll)w*w,(ll)a[1]),r=(ll)w*w+w;
		if(l<=r) solve(l,r,w);
	}
	printf("%lld\n",ans);
	return 0;
}
//ore no turn,draw!