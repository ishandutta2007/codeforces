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
int n,m,i,j,k,vis[105];
__int128 g[105][105],all;
__int128 pw(int x){return ((__int128)1)<<x;}
vector<pair<int,int> > ans;
int fa[105];int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
int dis[105][105];
bool check()
{
	if(ans.size()!=n-1)return 0;int i,j,k;fz1(i,n)fa[i]=i;
	ff(ans,it) fa[fnd(it->first)]=fnd(it->second);fz1(i,n)if(fnd(i)!=fnd(1))return 0;
	fz1(i,n)fz1(j,n)dis[i][j]=0x3f3f3f3f;ff(ans,it)dis[it->first][it->second]=dis[it->second][it->first]=1;
	fz1(i,n)dis[i][i]=0;
	fz1(k,n)fz1(i,n)fz1(j,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	fz1(i,n)fz1(j,n)if(i!=j)fz1(k,n) if((!!(g[i][j]&pw(k)))!=(dis[i][k]==dis[j][k])) return 0;
	return 1;
}
void dfs(int x,int fa)
{
	int i;vis[x]=1;
	fz1(i,n)if(!vis[i]){
		if(pw(x)&g[i][fa]){
			ans.push_back(make_pair(x,i));
			dfs(i,x);
		}
	}
}
void solve()
{
	double start=clock();
	read(n);fz1(i,n)fz1(j,n)g[i][j]=0;ans.clear();
	fz1(i,n)fz(j,i+1,n){
		fz1(k,n){char c;while(!isdigit(c=getchar()));if(c=='1')g[i][j]|=pw(k),g[j][i]|=pw(k);}
	}
	fz1(i,n)fz1(j,n)if((g[i][j]&pw(i))||(g[i][j]&pw(j))){
		puts("No");return;
	}
	fz(i,2,n){
		ans.clear();memset(vis,0,sizeof(vis));
		ans.push_back(make_pair(1,i));
		dfs(i,1);dfs(1,i);
		if(check()){
			puts("Yes");
			ff(ans,it) printf("%d %d\n",it->first,it->second);
			return;
		}
	}
	puts("No");
}
int main()
{
	int t;read(t);
	while(t--) solve();
	return 0;
}