#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first 
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,a[10004],G,R,ans=1000000000;
int dis[1003][10004];
bool vis[1003][10004];
deque<pii>dq;
int main(){
	read(n),read(m);
	for (int i=1;i<=m;i++) read(a[i]); 
	read(G),read(R);
	sort(a+1,a+1+m);
	for (int i=0;i<=G;i++) for (int j=1;j<=m;j++) dis[i][j]=1000000000;
	dis[0][1]=0;
	dq.push_back(mkp(0,1));
	while(!dq.empty()){
		pii x=dq.front();
		dq.pop_front();
		if (vis[x.fi][x.se]) continue;vis[x.fi][x.se]=1;
		if (x.fi==G){
			if (dis[0][x.se]>dis[G][x.se]+1)dis[0][x.se]=dis[G][x.se]+1,dq.push_back(mkp(0,x.se));
			continue;
		}
		if (x.se>1){
			int D=a[x.se]-a[x.se-1];
			if (D+x.fi<=G && dis[D+x.fi][x.se-1]>dis[x.fi][x.se])dis[D+x.fi][x.se-1]=dis[x.fi][x.se],dq.push_front(mkp(D+x.fi,x.se-1));
		}
		if (x.se<m){
			int D=a[x.se+1]-a[x.se];
			if (D+x.fi<=G && dis[D+x.fi][x.se+1]>dis[x.fi][x.se])dis[D+x.fi][x.se+1]=dis[x.fi][x.se],dq.push_front(mkp(D+x.fi,x.se+1));
		}
	}
	for (int i=0;i<=G;i++)if(dis[i][m]<1000000000)ans=min(ans,dis[i][m]*(G+R)+i);
	if (ans<1000000000) write(ans);
	else puts("-1");
}