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
inline void read(long long &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j;
long long a[500005],f[500005];
vector<long long> all;
long long s1[2100005],s2[2100005],s3[2100005];
void build(int x,int l,int r)
{
	s1[x]=s2[x]=s3[x]=-0x3f3f3f3f3f3f3f3fll;if(l==r)return;
	int mid=(l+r)/2;build(x+x,l,mid);build(x+x+1,mid+1,r);
}
void update(int x,int l,int r,int y,int c)
{
	s1[x]=max(s1[x],f[c]-c);
	s2[x]=max(s2[x],f[c]);
	s3[x]=max(s3[x],f[c]+c);
	if(l==r)return;int mid=(l+r)/2;
	if(y<=mid) update(x+x,l,mid,y,c); else update(x+x+1,mid+1,r,y,c);
}
long long query1(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return s1[x];
	int mid=(l+r)/2;long long res=-0x3f3f3f3f3f3f3f3fll;
	if(ql<=mid) res=max(res,query1(x+x,l,mid,ql,qr));
	if(qr>mid) res=max(res,query1(x+x+1,mid+1,r,ql,qr));
	return res;
}
long long query2(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return s2[x];
	int mid=(l+r)/2;long long res=-0x3f3f3f3f3f3f3f3fll;
	if(ql<=mid) res=max(res,query2(x+x,l,mid,ql,qr));
	if(qr>mid) res=max(res,query2(x+x+1,mid+1,r,ql,qr));
	return res;
}
long long query3(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return s3[x];
	int mid=(l+r)/2;long long res=-0x3f3f3f3f3f3f3f3fll;
	if(ql<=mid) res=max(res,query3(x+x,l,mid,ql,qr));
	if(qr>mid) res=max(res,query3(x+x+1,mid+1,r,ql,qr));
	return res;
}
void solve()
{
	all.clear();all.push_back(0);a[0]=0;
	read(n);fz1(i,n)read(a[i]),a[i]+=a[i-1],all.push_back(a[i]);
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	build(1,1,all.size());fz0g(i,n) a[i]=upper_bound(all.begin(),all.end(),a[i])-all.begin();
	update(1,1,all.size(),a[0],0);
	fz1(i,n){
		f[i]=-0x3f3f3f3f3f3f3f3fll;
		if(a[i]>1) f[i]=max(f[i],query1(1,1,all.size(),1,a[i]-1)+i);
		f[i]=max(f[i],query2(1,1,all.size(),a[i],a[i]));
		if(a[i]<all.size()) f[i]=max(f[i],query3(1,1,all.size(),a[i]+1,all.size())-i);
		update(1,1,all.size(),a[i],i);
	}
	printf("%lld\n",f[n]);
}
int main()
{
	int t;read(t);
	while(t--) solve(); 
	return 0;
}