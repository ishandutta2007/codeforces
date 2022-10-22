#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	int res=1;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
int n,m,cnt=0;
int a[2003];
int st[2];
int num[2003][2003];
short has[2][2003];
short vis[2003][2003][2];
ll total=0,dp[2003][2003][2][2],dat[2003][2003],dist[2][2003];
map<ll,short>mp;
map<ll,int>mpp;
vector<pii>g[2003];
ll d[2][2003];
void dijkstra(int wic){
	mp.clear(),mpp.clear();
	int s=st[wic];
	dist[wic][s]=1;
	priority_queue<pli,vector<pli>,greater<pli> > pq;
	pq.push(mkp(1,s));
	while(!pq.empty()){
		pli x=pq.top();pq.pop();
		if (has[wic][x.se]) continue;
		has[wic][x.se]=1;
		for (int i=0;i<g[x.se].size();i++) if (dist[wic][g[x.se][i].fi]>x.fi+g[x.se][i].se){
			dist[wic][g[x.se][i].fi]=x.fi+g[x.se][i].se;
			pq.push(mkp(dist[wic][g[x.se][i].fi],g[x.se][i].fi));
		}
	}
	for (int i=1;i<=n;i++) mp[dist[wic][i]]=1;
	cnt=0;
	for (map<ll,short>::iterator it=mp.begin();it!=mp.end();it++) mpp[it->first]=++cnt;
	for (int i=1;i<=n;i++) d[wic][i]=mpp[dist[wic][i]];
}
void init(int x){
	for (int i=1;i<=n;i++) if (d[0][i]<=x) num[x][0]++,dat[x][0]+=a[i];
	for (int i=1;i<=n;i++) if (d[0][i]>x) num[x][d[1][i]]++,dat[x][d[1][i]]+=a[i];
	for (int i=1;i<=n;i++) num[x][i]+=num[x][i-1],dat[x][i]+=dat[x][i-1];
}
void dfs(int x,int y,int wic){
	if (vis[x][y][wic]) return;
	vis[x][y][wic]=1;
	int fx=x,fy=y;
	if (wic==1) swap(fx,fy);
	if (num[fx][fy]==n){
		dp[x][y][wic][1]=0;
		return;
	}
	int a1=x+1,a2=y,b1=x,b2=y+1;
	if (wic==1) swap(a1,a2),swap(b1,b2);
	dfs(x+1,y,wic);
	dfs(y+1,x,wic^1);
	int num1=num[a1][a2]-num[fx][fy],num2=num[b1][b2]-num[fx][fy];
	ll get1=dat[a1][a2]-dat[fx][fy],get2=dat[b1][b2]-dat[fx][fy];
	if (num1==0){
		dp[x][y][wic][1]=dp[x+1][y][wic][1];
		dp[x][y][wic][0]=dp[x+1][y][wic][0];
	}else dp[x][y][wic][1]=max(dp[x+1][y][wic][0],dp[x+1][y][wic][1])+get1;
	if (num2==0){
		dp[x][y][wic][0]=max(dp[x][y][wic][0],total-dat[fx][fy]-dp[y+1][x][wic^1][1]);
	}else{
		if (max(dp[y+1][x][wic^1][0],dp[y+1][x][wic^1][1])!=-1e18)dp[x][y][wic][0]=max(dp[x][y][wic][0],total-dat[fx][fy]-max(dp[y+1][x][wic^1][0],dp[y+1][x][wic^1][1])-get2);
	}
	for (int i=0;i<2;i++) if (dp[x][y][wic][i]<-1e17) dp[x][y][wic][i]=-1e18;
}
int main(){
	for(int i=0;i<2003;dist[0][i]=dist[1][i]=1e17,i++)for(int j=0;j<2003;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)dp[i][j][k][l]=-1e18;
	read(n),read(m);
	for (int i=0;i<2;read(st[i]),i++); 
	for (int i=1;i<=n;read(a[i]),total+=a[i],i++);
	for (int i=0;i<m;i++){
		int x,y,w;
		read(x),read(y),read(w);
		g[x].push_back(mkp(y,w));
		g[y].push_back(mkp(x,w));
	}
	for (int i=0;i<2;dijkstra(i),i++); 
	for (int i=0;i<=n;i++) init(i); 
	dfs(0,0,0);
	ll ans=dp[0][0][0][1];
	if (ans>total-ans) puts("Break a heart");
	if (ans==total-ans) puts("Flowers");
	if (ans<total-ans) puts("Cry");
}