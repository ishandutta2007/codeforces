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
int t,n,m,i,j,f[100005],ans[100005],fa[100005];
vector<int> bi[100005];
void dfs(int x,int fa)
{
	::fa[x]=fa; 
	ff(bi[x],it)if(*it!=fa){
		if(abs(f[x])==1) f[*it]=2; else f[*it]=-1;
		dfs(*it,x);
	}
}
void dfs2(int x,int fa)
{
	::fa[x]=fa; 
	ff(bi[x],it)if(*it!=fa){
		if(f[x]==1||f[x]==2) f[*it]=-1; else f[*it]=2;
		dfs2(*it,x);
	}
}
void solve()
{
	read(n);fz1(i,n)bi[i].clear(),f[i]=ans[i]=0;
	fz1(i,n-1){int x,y;read(x);read(y);bi[x].push_back(y);bi[y].push_back(x);}
	int rt=0;fz1(i,n)if(bi[i].size()!=1) rt=i;
	f[rt]=1;dfs(rt,0);
	fz1(i,n){
		ans[i]=f[i];
		ff(bi[i],it)if(*it!=fa[i]) ans[i]-=f[*it];
		if(abs(ans[i])>100000) break;
	}
	if(i<=n){
		dfs2(rt,0);
		fz1(i,n){
			ans[i]=f[i];
			ff(bi[i],it)if(*it!=fa[i]) ans[i]-=f[*it];
			assert(abs(ans[i])<=100000);
		}
	}
	fz1(i,n) printf("%d%c",ans[i],spln(i,n));
}
int main()
{
	read(t);
	while(t--){
		solve();
	}
	return 0;
}