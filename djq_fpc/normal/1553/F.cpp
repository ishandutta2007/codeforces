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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int blk=550;
int n,m,i,j,k,a[200005];
long long ans;
struct blck
{
	long long c[400005];
	long long pre[555][555],suf[555][555];
	long long s[555],ps[555];
	void rebuild(int x)
	{
		int i;
		pre[x][0]=c[x*blk];
		fz1(i,blk-1){
			pre[x][i]=pre[x][i-1]+c[x*blk+i];
		}
		suf[x][blk-1]=c[x*blk+blk-1];
		for(i=blk-2;i>=0;i--){
			suf[x][i]=suf[x][i+1]+c[x*blk+i];
		}
		s[x]=pre[x][blk-1];
	}
	void rebuildall()
	{
		int i;
		ps[0]=s[0];
		fz1(i,blk-1) ps[i]=ps[i-1]+s[i];
	}
	void upd(int x,long long a)
	{
		c[x]+=a;
		rebuild(x/blk);
		rebuildall();
	}
	long long query(int l,int r)
	{
		if(l/blk==r/blk) return pre[l/blk][r%blk]-(l%blk==0?0:pre[l/blk][l%blk-1]);
		return suf[l/blk][l%blk]+pre[r/blk][r%blk]+ps[r/blk-1]-ps[l/blk];
	}
}b0,b1;
struct blck2
{
	long long pre[555][555],suf[555][555];
	long long ps[555];
	void upd(int l,int r,long long v)
	{
		if(l/blk==r/blk){
			pre[l/blk][l%blk]+=v;
			if(r%blk!=blk-1) pre[r/blk][r%blk+1]-=v;
			return;
		}
		pre[l/blk][l%blk]+=v;
		suf[r/blk][r%blk]+=v;
		ps[l/blk+1]+=v;ps[r/blk]-=v;
	}
	long long query(int x)
	{
		long long s=0;int i;
		int t=x%blk,p=x/blk;
		for(i=0;i<=t;i++) s+=pre[p][i];
		for(i=t;i<blk;i++) s+=suf[p][i];
		fz0g(i,p) s+=ps[i];
		return s;
	}
}c1;
int main()
{
	read(n);fz1(i,n)read(a[i]);
	fz1(i,n){
		for(j=0;j<=300000;j+=a[i]){
			int l=j,r=min(300000,j+a[i]-1);
			ans+=b1.query(l,r)-b0.query(l,r)*j;
		}
		b0.upd(a[i],1);
		b1.upd(a[i],a[i]);
		
		ans+=1ll*(i-1)*a[i]+c1.query(a[i]);
		for(j=0;j<=300000;j+=a[i]){
			int l=j,r=min(300000,j+a[i]-1);
			c1.upd(l,r,-j);
		}
		
		printf("%lld ",ans);
	}
	return 0;
}