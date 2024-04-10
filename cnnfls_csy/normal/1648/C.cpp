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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
int n,m,ini,i,j,fac[200005],inv[200005],fi[200005],c[200005],b[200005],ans;
int tag[800005],sum[800005];
void build(int x,int l,int r)
{
	tag[x]=1;
	if(l==r){sum[x]=1ll*ini*c[l]%mod;return;}
	int mid=(l+r)/2;build(x+x,l,mid);build(x+x+1,mid+1,r);
	sum[x]=(sum[x+x]+sum[x+x+1])%mod;
}
void upd(int x,int c)
{
	sum[x]=1ll*sum[x]*c%mod;
	tag[x]=1ll*tag[x]*c%mod;
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){upd(x,c);return;}
	int mid=(l+r)/2;if(ql<=mid)update(x+x,l,mid,ql,qr,c);if(qr>mid)update(x+x+1,mid+1,r,ql,qr,c);
	sum[x]=1ll*tag[x]*(sum[x+x]+sum[x+x+1])%mod;
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2,s=0;
	if(ql<=mid)s=(s+query(x+x,l,mid,ql,qr))%mod;if(qr>mid)s=(s+query(x+x+1,mid+1,r,ql,qr))%mod;
	return 1ll*s*tag[x]%mod;
}
int main()
{
	fac_init(200002);
	read(n);read(m);fz1(i,n){int x;read(x);c[x]++;}fz1(i,m)read(b[i]);
	ini=1;fz1(i,200000) ini=1ll*fi[c[i]]*ini%mod;build(1,1,200000);
	fz1(i,m){
		if(i>n) break;
		if(b[i]>1) ans=(ans+1ll*fac[n-i]*query(1,1,200000,1,b[i]-1))%mod;
		if(c[b[i]]!=0){
			if(b[i]>1) update(1,1,200000,1,b[i]-1,c[b[i]]);
			if(b[i]<200000) update(1,1,200000,b[i]+1,200000,c[b[i]]);
			update(1,1,200000,b[i],b[i],c[b[i]]-1);
			ini=1ll*ini*c[b[i]]%mod;
			c[b[i]]--;
		}
		else{
			i=-1;break;
		}
	}
	if(n<m&&i!=-1){
		ans=(ans+1)%mod;
	}
	printf("%d\n",ans); 
	return 0;
}