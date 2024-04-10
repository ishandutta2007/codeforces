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
long long ans;
int n,m,i,j,dfn[300005],dep[300005],deg[300005],pos[300005],fa[300005][19],vis[300005],ti;
vector<int> bi[300005],res[300005];
int sl[300005],sr[300005];
void dfs1(int x)
{
	ff(bi[x],it){
		dep[*it]=dep[x]+1;
		fa[*it][0]=x;
		dfs1(*it);
	}
}
bool cmp(int x,int y)
{
	return dfn[x]>dfn[y];
}
int gtmi(int x)
{
	int s=-1;
	ff(bi[x],it)if(dfn[*it]>dfn[x]){
		if(s==-1||dfn[*it]<dfn[s]) s=*it;
	}
	return s;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y],i;
	fd0g(i,18)if((t>>i)&1) x=fa[x][i];
	if(x==y) return x;
	fd0g(i,18)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];y=fa[y][i];
	}
	return fa[x][0];
}
void dfs2(int x)
{
	sort(bi[x].begin(),bi[x].end(),cmp);
	ff(bi[x],it){
		if(dfn[*it]<dfn[x])continue;
		if(res[x][sr[x]]!=0&&res[x][sr[x]]!=*it){
			puts("NO");exit(0);
		}
		res[x][sr[x]--]=*it;
		dfs2(*it);
	}
	if(dfn[x]!=ti){
		puts("NO");exit(0);
	}
	ti--;
}
void dfs3(int x)
{
	dfn[x]=++ti;
	ff(res[x],it){
		dfs3(*it);
	}
}
int main()
{
	read(n);
	fz1(i,n){
		read(dfn[i]);
		pos[dfn[i]]=i;
	}
	fz1(i,n-1){
		int x,y;
		read(x);read(y);
		bi[x].push_back(y);
		deg[x]++;
	}
	fz1(i,n){
		res[i].resize(bi[i].size());
		sr[i]=((int)res[i].size())-1;
	}
	dfs1(1);
	fz1(j,18)fz1(i,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	if(dfn[1]!=1){
		int t=dfn[1]-1;
		while(pos[t]!=1){
			int x=pos[t],y=fa[x][0];
			swap(dfn[x],dfn[y]);
			swap(pos[dfn[x]],pos[dfn[y]]);
			if(dfn[y]>dfn[x]||gtmi(y)!=x){
				puts("NO");
				return 0;
			}
			ans++;
		}
	}
	int lst=0;
	fz1(i,dfn[1]-1){
		int x=pos[i];
		if(deg[x]){
			puts("NO");
			return 0;
		}
		if(lst&&lca(lst,x)!=fa[lst][0]){
			puts("NO");
			return 0;
		}
		lst=x;
		deg[fa[x][0]]--;
		ans+=dep[x];
		int y=x;
		while(y!=1&&!vis[y]){
			res[fa[y][0]][sl[fa[y][0]]++]=y;
			vis[y]=1;
			y=fa[y][0];
		}
	}
	ti=n;dfs2(1);
	ti=0;dfs3(1);
	puts("YES");
	printf("%lld\n",ans);
	fz1(i,n){
		printf("%d ",dfn[i]);
	}
	return 0;
}