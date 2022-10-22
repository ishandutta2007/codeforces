#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,cnt,p[3003],ans=1e9,dis[3003][3003],t[3003];
vector<pii>g[3003];
void dfs(int x,int par){
	p[x]=par;
	for (int i=0;i<g[x].size();i++) if (g[x][i].fi!=par) dfs(g[x][i].fi,x),t[g[x][i].fi]=g[x][i].se,cnt+=g[x][i].se;
}
void dfs1(int x,int par,int d,int rt){
	dis[rt][x]=d;
	for (int i=0;i<g[x].size();i++) if (g[x][i].fi!=par) dfs1(g[x][i].fi,x,d+g[x][i].se,rt);
}
bool par[3003][3003];
int main(){
	read(n);
	if (n==1){
		puts("0");return 0;
	}
	for (int i=1;i<n;i++){
		int x,y;read(x),read(y),g[x].push_back(mkp(y,0)),g[y].push_back(mkp(x,1));
	}
	dfs(1,-1);
	for (int i=1;i<=n;i++) dfs1(i,-1,0,i);
	for (int i=1;i<=n;i++) for (int j=i;j!=-1;par[i][j]=1,j=p[j]);
	for (int i=2;i<=n;i++){
		int ans1=0,ans2=0;
		for (int j=1;j<=n;j++){
			if (par[j][i])ans1=max(ans1,dis[i][j]-dis[j][i]);
			else ans2=max(ans2,dis[1][j]-dis[j][1]);
		}
		ans=min(ans,cnt-ans1-ans2-t[i]);
	}
	write(ans);
}