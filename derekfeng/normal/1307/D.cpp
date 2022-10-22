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
vector<int>g[200004];
int n,m,K,dist[2][200004],ans,a[200004];
void bfs(int s,int go){
	queue <int> que;
	que.push(s),dist[go][s]=0;
	while (!que.empty()){
		int x=que.front();que.pop();
		for (int i=0;i<g[x].size();i++) if (dist[go][g[x][i]]==-1)
			que.push(g[x][i]),dist[go][g[x][i]]=dist[go][x]+1; 
	}
}
bool cmp(pii A,pii B){
	return A.fi-A.se<B.fi-B.se;
}
int main(){
	memset(dist,-1,sizeof(dist)); 
	read(n),read(m),read(K);
	for (int i=1;i<=K;i++) read(a[i]);
	for (int i=1;i<=m;i++){
		int x,y;read(x),read(y),g[x].push_back(y),g[y].push_back(x);
	}
	bfs(1,0),bfs(n,1);
	vector<pii>v;
	for (int i=1;i<=K;i++)
		v.push_back(mkp(dist[0][a[i]],dist[1][a[i]])); 
	sort (v.begin(),v.end(),cmp);
	int now=v[0].fi,ans=0;
	for (int i=1;i<v.size();i++) ans=max(ans,v[i].se+1+now),now=v[i].fi;
	write(min(dist[0][n],ans));
}