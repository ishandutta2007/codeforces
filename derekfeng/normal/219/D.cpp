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
int n,num,dp[200004],dd[200004];
vector<pii>g[200004];
void dfs(int x,int par,int now){
	dp[x]=now;
	for (int i=0;i<g[x].size();i++) if(g[x][i].fi!=par){
		dfs(g[x][i].fi,x,now+g[x][i].se);
		num+=g[x][i].se;
	}
}
void dfs1(int x,int par,int now){
	dd[x]=now;
	for (int i=0;i<g[x].size();i++) if(g[x][i].fi!=par)
		dfs1(g[x][i].fi,x,now+1-g[x][i].se);
}
int main(){
	read(n);
	for (int i=0;i<n-1;i++){
		int x,y;read(x),read(y);
		g[x].push_back(mkp(y,1));
		g[y].push_back(mkp(x,0));
	}
	dfs(1,-1,0);
	dfs1(1,-1,0);
	int ans=1e9;
	for (int i=1;i<=n;i++)
		ans=min(n-1-(dd[i]+num-dp[i]),ans);
	write(ans);puts("");
	for (int i=1;i<=n;i++)
		if (n-1-(dd[i]+num-dp[i])==ans) write(i),putchar(' ');
}