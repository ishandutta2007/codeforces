#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[250005],f[250005];
int sup[250005],tup;
int sdw[250005],tdw;
struct seg
{
	int mi[1000005];
	void build(int x,int l,int r)
	{
		mi[x]=0x3f3f3f3f;
		if(l==r){return;}int mid=(l+r)/2;
		build(x+x,l,mid);build(x+x+1,mid+1,r);
	}
	void update(int x,int l,int r,int y,int c)
	{
		if(l==r){mi[x]=c;return;}int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
		mi[x]=min(mi[x+x],mi[x+x+1]);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(ql>qr)return 0x3f3f3f3f;
		if(ql<=l&&r<=qr)return mi[x];int mid=(l+r)/2,s=0x3f3f3f3f;
		if(ql<=mid)s=min(s,query(x+x,l,mid,ql,qr));
		if(qr>mid)s=min(s,query(x+x+1,mid+1,r,ql,qr));
		return s;
	}
}trup,trdw;
void solve()
{
	read(n);fz1(i,n)read(a[i]);
	fz1(i,n)f[i]=0x3f3f3f3f;f[n]=0;
	tup=tdw=1;sup[1]=sdw[1]=n;
	trup.build(1,1,n);trdw.build(1,1,n);
	trup.update(1,1,n,1,0);
	trdw.update(1,1,n,1,0);
	fd1(i,n-1){
		f[i]=0x3f3f3f3f;
		f[i]=min(f[i],f[sup[tup]]+1);
		f[i]=min(f[i],f[sdw[tdw]]+1);
		while(tup&&a[sup[tup]]<a[i])tup--;
		while(tdw&&a[sdw[tdw]]>a[i])tdw--;
		int lim1=(tup&&a[sup[tup]]>a[i]?sup[tup]:n),lim2=(tdw&&a[sdw[tdw]]<a[i]?sdw[tdw]:n);
		int t=tup+1,l=0,r=tup,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(sup[mid]<=lim2)r=mid-1,t=mid;
			else l=mid;
		}
		f[i]=min(f[i],trup.query(1,1,n,t,tup)+1);
		t=tdw+1,l=0,r=tdw,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(sdw[mid]<=lim1)r=mid-1,t=mid;
			else l=mid;
		}
		f[i]=min(f[i],trdw.query(1,1,n,t,tdw)+1);
		sup[++tup]=i;trup.update(1,1,n,tup,f[i]);
		sdw[++tdw]=i;trdw.update(1,1,n,tdw,f[i]);
	}
	printf("%d\n",f[1]);
}
int main()
{
	int t;read(t);
	while(t--) solve();
	return 0;
}