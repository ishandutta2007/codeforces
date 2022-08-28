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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define incm(x,y) {x=((x)+(y))%mod;}
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
int n,m,i,j,typ[100005];
int a[100005],f[100005],fl[100005],fr[100005];
struct seg1
{
	struct nd1
	{
		int mx,s;
	}tr[400005];
	nd1 merge(nd1 x,nd1 y)
	{
		if(x.mx>y.mx) return x;
		if(x.mx<y.mx) return y;
		return (nd1){x.mx,x.s+y.s};
	}
	void pushup(int x)
	{
		tr[x]=merge(tr[x+x],tr[x+x+1]);
	}
	void update(int x,int l,int r,int y)
	{
		if(l==r){
			tr[x].mx^=1;
			tr[x].s=1;
			return;
		}
		int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y);else update(x+x+1,mid+1,r,y);
		pushup(x);
	}
	nd1 query(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return tr[x];
		int mid=(l+r)/2;
		if(qr<=mid)return query(x+x,l,mid,ql,qr);
		if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
		return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
	}
}tr1;
struct seg2
{
	int mx[400005];
	void pushup(int x)
	{
		mx[x]=min(mx[x+x],mx[x+x+1]);
	}
	void update(int x,int l,int r,int y,int c)
	{
		if(l==r){
			mx[x]+=c;
			return;
		}
		int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return mx[x];
		int mid=(l+r)/2;
		if(qr<=mid)return query(x+x,l,mid,ql,qr);
		if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
		return max(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
	}
}tr2;
bool check()
{
	int t=min(i-1,n-j+1);
	if(!fl[t]) return 0;
	t=max(m-j+1,i-(n-m)-1);
	if(!fr[m-max(-1,t-1)]) return 0;
	if(tr2.mx[1]<0) return 0;
	if(tr1.tr[1].mx==1&&tr1.tr[1].s>((n&1)&&(i<=m&&m<=j))) return 0;
	return 1;
}
void add(int x)
{
	typ[x]++;
	if(x*2-1!=n){
		if(!typ[n-x+1]){
			tr1.update(1,1,n,a[x]);
			tr1.update(1,1,n,a[n-x+1]);
			tr2.update(1,1,n,a[x],1);
			tr2.update(1,1,n,a[n-x+1],-1);
		}
		else{
			tr2.update(1,1,n,a[x],2);
		}
	}
	else{
		tr1.update(1,1,n,a[x]);
		tr2.update(1,1,n,a[x],1);
	}
}
void del(int x)
{
	typ[x]--;
	if(x*2-1!=n){
		if(!typ[n-x+1]){
			tr1.update(1,1,n,a[x]);
			tr1.update(1,1,n,a[n-x+1]);
			tr2.update(1,1,n,a[x],-1);
			tr2.update(1,1,n,a[n-x+1],1);
		}
		else{
			tr2.update(1,1,n,a[x],-2);
		}
	}
	else{
		tr1.update(1,1,n,a[x]);
		tr2.update(1,1,n,a[x],-1);
	}
}
int main()
{
	read(n);m=(n+1)/2;
	fz1(i,n) read(a[i]);
	fz1(i,m) f[i]=(a[i]==a[n-i+1]);
	fl[0]=fr[m+1]=1;
	fz1(i,m){
		fl[i]=(fl[i-1]&&f[i]);
	}
	fd1(i,m){
		fr[i]=(fr[i+1]&&f[i]);
	}
	j=1;
	long long ans=0;
	fz1(i,n){
		while(j<=i) add(j++);
		while(j<=n&&!check()){
			add(j++);
		}
		if(check())ans+=(n-j+2);
		while(j<=i) add(j++);del(i);
	}
	cout<<ans<<endl;
	return 0;
}