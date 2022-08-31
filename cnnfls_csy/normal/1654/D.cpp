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
int qp(int x,int y){int z=1;while(y){if(y&1){z=1ll*z*x%mod;}x=1ll*x*x%mod;y/=2;}return z;}
int t,n,m,i,j,np[200005],p[200005],pc,res[200005],fi[200005],ed[200005],ti;
int px[200005],py[200005],p1[200005],p2[200005];
int fa[200005],dis[200005],mx[200005],pa[200005];
vector<int> v[200005],d[200005],e[200005];
vector<int> bi[200005];
int fnd(int x)
{
	if(fa[x]==x) return x;
	int t=fnd(fa[x]);dis[x]+=dis[fa[x]];
	return fa[x]=t;
}
void merge(int x,int y,int z) // dis[x]+z=dis[y]
{
	fnd(x);z-=dis[x];x=fa[x];
	fnd(y);z+=dis[y];y=fa[y];
	if(x==y) return;
	fa[x]=y;dis[x]=z;
}
void dfs(int x,int p)
{
	pa[x]=p;fi[x]=++ti;
	ff(bi[x],it){
		int y=px[*it]^py[*it]^x;
		if(y==p) continue;
		if(px[*it]==y) swap(px[*it],py[*it]),swap(p1[*it],p2[*it]);
		res[y]=1ll*res[x]*p2[*it]%mod*qp(p1[*it],mod-2)%mod;
		dfs(y,x);
	}
	ed[x]=ti;
}
void solve()
{
	read(n);fz1(i,n) v[i].clear(),e[i].clear(),res[i]=1,bi[i].clear();
	fz1(i,n-1){
		read(px[i]);read(py[i]);read(p1[i]);read(p2[i]);
		ff(d[p1[i]],it) /*v[*it].push_back(px[i]),v[*it].push_back(py[i]),*/e[*it].push_back(i);
		ff(d[p2[i]],it) /*v[*it].push_back(px[i]),v[*it].push_back(py[i]),*/e[*it].push_back(i);
		bi[px[i]].push_back(i);bi[py[i]].push_back(i);
	}
	int coef=1;
	ti=0;dfs(1,0);
	fz(i,2,n)if(!np[i]){
//		sort(v[i].begin(),v[i].end());v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
		sort(e[i].begin(),e[i].end());e[i].resize(unique(e[i].begin(),e[i].end())-e[i].begin());
		vector<pair<int,int> > v;
		int mx=0,cur=0;
		ff(e[i],it){
			int c=0;
			while(p1[*it]%i==0) p1[*it]/=i,c++;
			while(p2[*it]%i==0) p2[*it]/=i,c--;
			v.push_back(make_pair(fi[py[*it]],c));
			v.push_back(make_pair(ed[py[*it]]+1,-c));
		}
		sort(v.begin(),v.end());
		ff(v,it) cur+=it->second,mx=max(mx,cur);
		coef=1ll*coef*qp(i,mx)%mod;
	}
	int ans=0;
	fz1(i,n) ans=(ans+res[i])%mod;
	printf("%d\n",1ll*coef*ans%mod);
}
int main()
{
	fz(i,2,200000){
		if(!np[i]){
			p[++pc]=i;
			fz1(j,200000/i){
				if(j>1) np[i*j]=1;
				d[i*j].push_back(i);
			}
		}
	}
	read(t);
	while(t--) solve();
	return 0;
}