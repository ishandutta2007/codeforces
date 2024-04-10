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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,q,i,j;
long long a[105],b[100005];
long long sum[400005],sum2[400005],tag[400005],mx[400005];
int len[400005];
void pushup(int x)
{
	sum[x]=sum[x+x]+sum[x+x+1]+tag[x]*len[x];
	sum2[x]=sum2[x+x]+sum[x+x]*len[x+x+1]+sum2[x+x+1]+tag[x]*len[x]*(len[x]+1)/2;
	mx[x]=max(mx[x+x],mx[x+x+1])+tag[x];
}
void build(int x,int l,int r)
{
	len[x]=r-l+1;
	if(l==r){
		sum[x]=mx[x]=sum2[x]=b[l];
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	pushup(x);
}
void upd(int x,long long y)
{
	sum[x]+=y*len[x];
	sum2[x]+=y*len[x]*(len[x]+1)/2;
	tag[x]+=y;mx[x]+=y;
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){upd(x,c);return;}
	int mid=(l+r)/2;
	if(ql<=mid) update(x+x,l,mid,ql,qr,c);
	if(qr>mid) update(x+x+1,mid+1,r,ql,qr,c);
	pushup(x);
}
long long ans;
int p,rem,cnt;
void query(int x,int l,int r,long long ctag)
{
	if(p>n||mx[x]+ctag<=a[p]){
		ans+=ctag*rem*(rem+1)/2;
		ans+=sum2[x]+(rem-=len[x])*sum[x];
		ans-=ctag*rem*(rem+1)/2;
		return;
	}
	if(l==r){
		while(p<=n&&a[p]<mx[x]+ctag){
			ans+=(rem--)*a[p++];
		}
		ans+=(rem--)*(mx[x]+ctag);
		return;
	}
	int mid=(l+r)/2;
	ctag+=tag[x];
	query(x+x,l,mid,ctag);
	query(x+x+1,mid+1,r,ctag);
}
long long calc()
{
	ans=(a[1]+b[1])*(n+m-1);
	rem=n+m-2;p=2;
	query(1,2,m,0);
	while(p<=n) ans+=(rem--)*a[p++];
	return ans;
}
int main()
{
	read(n);read(m);read(q);
	fz1(i,n)read(a[i]);
	fz1(i,m)read(b[i]);
	fd(i,n,2) a[i]=a[i]-a[i-1];
	fd(i,m,2) b[i]=b[i]-b[i-1];
//	fz1(i,n) a[i]=a[i-1]+rand();
//	fz1(i,m) b[i]=b[i-1]+rand();
	build(1,2,m);
	while(q--){
		int op,k,d;
		read(op);read(k);read(d);
		if(op==1){
			fz(i,n-k+1,n) a[i]+=d;
		}
		else{
			if(k==m) b[1]+=d,k--;
			update(1,2,m,m-k+1,m,d);
		}
		printf("%lld\n",calc());
//		cerr<<cnt<<endl;
	}
	return 0;
}