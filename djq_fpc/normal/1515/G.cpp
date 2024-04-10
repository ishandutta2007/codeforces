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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
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
vector<pair<int,int> > bi[200005];
int dfn[200005],low[200005],bel[200005],scc,ti;
stack<int> stk;
int vis[200005],vis2[200005];long long dis[200005],res[200005],dis2[200005];
void tarjan(int x)
{
	stk.push(x);dfn[x]=low[x]=++ti;
	ff(bi[x],it){
		if(!dfn[it->fi]){
			tarjan(it->fi);
			low[x]=min(low[x],low[it->fi]);
		}
		else if(!bel[it->fi]){
			low[x]=min(low[x],dfn[it->fi]);
		}
	}
	if(low[x]==dfn[x]){
		scc++;bel[x]=scc;
		while(stk.top()!=x){
			bel[stk.top()]=scc;
			stk.pop();
		}
		stk.pop();
	}
}
void dfs(int x)
{
	vis[x]=1;
	ff(bi[x],it){
		if(bel[it->fi]!=bel[x]) continue;
		if(vis[it->fi]){
			if(vis[it->first]==1) res[bel[x]]=__gcd(res[bel[x]],dis[x]-dis[it->fi]+it->se);
		}
		else{
			dis[it->first]=dis[x]+it->second;
			dfs(it->first);
		}
		if(vis2[it->first]){
			res[bel[x]]=__gcd(res[bel[x]],dis[x]+it->se+dis2[it->first]);
			dis2[x]=dis2[it->first]+it->se;
			vis2[x]=1;
		}
	}
}
int main()
{
	read(n);read(m);
	fz1(i,m){
		int x,y,z;
		read(x);read(y);read(z);
		bi[x].push_back(mk(y,z));
	}
	fz1(i,n)if(!dfn[i]) tarjan(i);
	fz1(i,n)if(!vis[i]){
		vis2[i]=1;
		dfs(i);
	}
	read(q);
	while(q--){
		int x;
		long long a,b;
		read(x);read(a);read(b);
		x=bel[x];
		long long t=__gcd(res[x],b);
		if((b-a)%t==0) puts("YES"); else puts("NO");
	}
	return 0;
}