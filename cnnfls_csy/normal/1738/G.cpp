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
typedef long long i64;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
inline void read(i64 &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[1005][1005],res[1005][1005];
int fir[1005];
struct seg
{
	int mi[4005];
	void build(int x,int l,int r)
	{
		if(l==r){mi[x]=fir[l];return;}int mid=(l+r)/2;
		build(x+x,l,mid);build(x+x+1,mid+1,r);
		mi[x]=min(mi[x+x],mi[x+x+1]);
	}
	void update(int x,int l,int r,int y)
	{
		if(l==r){mi[x]=fir[l];return;}int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y);else update(x+x+1,mid+1,r,y);
		mi[x]=min(mi[x+x],mi[x+x+1]);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(ql<=l&&r<=qr) return mi[x];int mid=(l+r)/2,res=0x3f3f3f3f;
		if(ql<=mid) res=min(res,query(x+x,l,mid,ql,qr));
		if(qr>mid) res=min(res,query(x+x+1,mid+1,r,ql,qr));
		return res;
	}
}tr;
void solve()
{
	read(n);read(m);
	fz1(i,n) fir[i]=1;
	fz1(i,n)fz1(j,n){
		res[i][j]=0;
		char c;while(!isdigit(c=getchar()));
		a[i][j]=(c&1);
	}
	fz1(i,m-1)fz(j,n-(m-1-i),n) res[i][j]=res[j][i]=1,a[i][j]=a[j][i]=1;
	fz1(i,n){
		while(fir[i]<=n&&a[i][fir[i]]) fir[i]++;
	}
	tr.build(1,1,n);
	fz(i,n-m+2,n){
		int x=i,y=i-(n-m+1);
		int tx=y,ty=x;
		while(x>tx||y<ty){
			while(y<ty&&y<tr.query(1,1,n,1,x)){
				y++,res[x][y]=a[x][y]=1;
				if(fir[x]<=n&&a[x][fir[x]]){
					while(fir[x]<=n&&a[x][fir[x]]) fir[x]++,tr.update(1,1,n,x);
				}
			}
			if(x>tx){
				x--;res[x][y]=a[x][y]=1;
				if(fir[x]<=n&&a[x][fir[x]]){
					while(fir[x]<=n&&a[x][fir[x]]) fir[x]++,tr.update(1,1,n,x);
				}
			}
		}
	}
	fz1(i,n){
		if(fir[i]<=n){
			puts("NO");
			return;
		}
	}
	puts("YES");
	int _=0;
	fz1(i,n){
		fz1(j,n){
			printf("%d",res[i][j]);
			if(!res[i][j]) _++;
		}
		puts("");
	}
	assert(_==(n-m+1)*(n-m+1));
}
int main()
{
	int t;read(t);
	while(t--) solve();
	return 0;
}