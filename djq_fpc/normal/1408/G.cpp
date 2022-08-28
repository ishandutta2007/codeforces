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
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
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
int n,m,i,j,cnt,pa[3015],fi[3015],ed[3015],dp[1505][1505],ti,sz[3015],sz2[3015];
vector<int> v[3015],bi[3015];
struct ii
{
	int x,y,z;
}e[2250005];
int fnd(int x)
{
	if(pa[x]==x) return x;
	return pa[x]=fnd(pa[x]);
}
bool cmp(ii x,ii y)
{
	return x.z<y.z;
}
void dfs(int x)
{
	fi[x]=ti+1;
	if(x<=n)ti++;
	ff(bi[x],it){
		dfs(*it);
	}
	ed[x]=ti;
	if(sz[x]*(sz[x]-1)/2==sz2[x]) v[ed[x]].push_back(fi[x]);
}
int main()
{
	read(n);
	fz1(i,n){
		fz1(j,n){
			int x;
			read(x);
			if(i<j){
				e[++m]=(ii){i,j,x};
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	fz1(i,n)sz[i]=1;
	fz1(i,n) pa[i]=i;cnt=n;
	fz1(i,m){
		if(fnd(e[i].x)==fnd(e[i].y)){
			sz2[fnd(e[i].x)]++;
			continue;
		}
		cnt++;int x=fnd(e[i].x),y=fnd(e[i].y);
		pa[x]=pa[y]=pa[cnt]=cnt;sz[cnt]=sz[x]+sz[y];sz2[cnt]=sz2[x]+sz2[y]+1;
		bi[cnt].push_back(x);bi[cnt].push_back(y);
	}
	dfs(cnt);
	dp[0][0]=1;
	fz1(i,n){
		ff(v[i],it) fz1(j,n)inc(dp[i][j],dp[*it-1][j-1])
	}
	fz1(i,n){
		printf("%d%c",dp[n][i],spln(i,n));
	}
	return 0;
}