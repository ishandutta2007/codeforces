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
	FILE* _=freopen("1.in","r",stdin);
#endif
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
int n,m,i,j,a[200005],nxt[200005],lim[200005],vis[200005];
map<int,int> mp;
vector<int> v[200005];
int cur,ub;
void ins(int x,int y)
{
	cur=max(cur,x);v[x].push_back(y);
	ub=min(ub,y);
}
void solve()
{
	read(n);read(m);fz1(i,n)read(a[i]);mp.clear();
	cur=0;ub=n;fz1(i,n) v[i].clear();
	fz1(i,n) lim[i]=vis[i]=0;
	fd1(i,n) nxt[i]=mp[a[i]],mp[a[i]]=i;
	while(m--){int l,r;read(l);read(r);lim[l]=max(lim[l],r);}
	fz1(i,n) lim[i]=max(lim[i],lim[i-1]);
	int sl=0x3f3f3f3f,sr=0;
	fz1(i,n)if(!vis[i]){
		int x=i;
		while(nxt[x]&&nxt[x]<=lim[x]){
			x=nxt[x];vis[x]=1;
			if(nxt[x]&&nxt[x]<=lim[x]) sl=min(sl,x),sr=max(sr,x);
		}
		if(x!=i&&x<=lim[i]) ins(i,x);
	}
	int ans=n;
	fz1(i,ub){
		cur=max(cur,i-1);
		int l=min(sl,i),r=max(cur,sr);
		ans=min(ans,r-l+1);
		ff(v[i],it) cur=max(cur,*it);
	}
	printf("%d\n",ans);
}
int main()
{
	int t;read(t);while(t--)solve();
	return 0;
}