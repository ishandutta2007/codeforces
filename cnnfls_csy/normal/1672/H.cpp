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
int n,m,i,j,a[200005];
int c0[800005],c1[800005];
int d10[800005],d01[800005];
void build(int x,int l,int r)
{
	if(l==r){
		if(a[l]==0) c0[x]=1; else c1[x]=1;
		if(l<n){
			if(a[l]==0&&a[l+1]==1) d01[x]=1;
			if(a[l]==1&&a[l+1]==0) d10[x]=1;
		}
		return;
	}
	int mid=(l+r)/2;build(x+x,l,mid);build(x+x+1,mid+1,r);
	c0[x]=c0[x+x]+c0[x+x+1];
	c1[x]=c1[x+x]+c1[x+x+1];
	d10[x]=d10[x+x]+d10[x+x+1];
	d01[x]=d01[x+x]+d01[x+x+1];
}
int query1(int x,int l,int r,int ql,int qr)
{
	if(ql>qr)return 0;if(ql<=l&&r<=qr)return c0[x];
	int mid=(l+r)/2,s=0;
	if(ql<=mid) s+=query1(x+x,l,mid,ql,qr);
	if(qr>mid) s+=query1(x+x+1,mid+1,r,ql,qr);
	return s;
}
int query2(int x,int l,int r,int ql,int qr)
{
	if(ql>qr)return 0;if(ql<=l&&r<=qr)return c1[x];
	int mid=(l+r)/2,s=0;
	if(ql<=mid) s+=query2(x+x,l,mid,ql,qr);
	if(qr>mid) s+=query2(x+x+1,mid+1,r,ql,qr);
	return s;
}
int query3(int x,int l,int r,int ql,int qr)
{
	if(ql>qr)return 0;if(ql<=l&&r<=qr)return d01[x];
	int mid=(l+r)/2,s=0;
	if(ql<=mid) s+=query3(x+x,l,mid,ql,qr);
	if(qr>mid) s+=query3(x+x+1,mid+1,r,ql,qr);
	return s;
}
int query4(int x,int l,int r,int ql,int qr)
{
	if(ql>qr)return 0;if(ql<=l&&r<=qr)return d10[x];
	int mid=(l+r)/2,s=0;
	if(ql<=mid) s+=query4(x+x,l,mid,ql,qr);
	if(qr>mid) s+=query4(x+x+1,mid+1,r,ql,qr);
	return s;
}
int main()
{
	read(n);read(m);fz1(i,n){char c;while(!isdigit(c=getchar()));a[i]=(c&15);}
	build(1,1,n);
	while(m--){
		int l,r;read(l);read(r);
		if(l==r){puts("1");continue;}
		int tmp=query1(1,1,n,l,r)-query2(1,1,n,l,r);
		int ans=(r-l+1+abs(tmp))-query3(1,1,n,l,r-1)-query4(1,1,n,l,r-1); 
		if(a[r]==0&&tmp>0) ans--;
		if(a[r]==1&&tmp<0) ans--;
		ans/=2;
		printf("%d\n",ans+1);
	}
	return 0;
}