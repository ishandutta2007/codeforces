#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int n,m;
int dg[N],xd[N];
int dis[N];
int vis[N];

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(x==n)continue;
		add(y,x);
		dg[x]++;
	}
	priority_queue<pair<int,int>> q;
	memset(dis,1,sizeof(dis));
	dis[n]=0;
	q.push({0,n});
	while(q.size()){
		int nw=q.top().second;q.pop();
		if(vis[nw])continue;vis[nw]=1;
		fore(nw){
			if(vis[_to])continue;
			dg[_to]--;
			xd[_to]=dis[nw]+1;
			if(xd[_to]+dg[_to]<dis[_to])
				dis[_to]=xd[_to]+dg[_to],q.push({-dis[_to],_to});
		}
	}
	cout<<dis[1]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}