#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1e3+10;
int n;
pair<pair<int,int>,pair<int,int>>q[N];
vector<int>X,Y;int vis[N*2][N*2];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y){
	if(0<x&&x<=X.size()&&0<y&&y<=Y.size()){
		if(vis[x][y])return;
		vis[x][y]=2;
		for(int i=0;i<4;i++)
			dfs(x+dx[i],y+dy[i]);
	}
}
signed main(){
	cin>>n;
	
	X.pb(-2e9+10);X.pb(-1);X.pb(0);
	Y.pb(-2e9+10);Y.pb(-1);Y.pb(0);
	
	int nowx=0,nowy=0;
	for(int i=1;i<=n;i++){
		char op;int len;cin>>op>>len;
		int nx=nowx,ny=nowy;
		if(op=='L')nx-=len;
		if(op=='R')nx+=len;
		if(op=='D')ny-=len;
		if(op=='U')ny+=len;
		X.pb(nx);X.pb(nx-1);
		Y.pb(ny);Y.pb(ny-1); 
		q[i]=mp(mp(nowx,nowy),mp(nx,ny));
		nowx=nx,nowy=ny;
	}
	auto init=[&](vector<int>&a){sort(a.begin(),a.end());a.resize(unique(a.begin(),a.end())-a.begin());};
	auto get=[&](vector<int>&a,int b){return lower_bound(a.begin(),a.end(),b)-a.begin();};
	init(X);init(Y);
	for(int i=1;i<=n;i++){
		int x1=get(X,q[i].first.first),y1=get(Y,q[i].first.second);
		int x2=get(X,q[i].second.first),y2=get(Y,q[i].second.second);
		if(x1==x2)for(int i=min(y1,y2);i<=max(y1,y2);i++)vis[x1][i]=1;
		if(y1==y2)for(int i=min(x1,x2);i<=max(x1,x2);i++)vis[i][y1]=1;
	}
	dfs(1,1);
	long long ans=0;
	for(int i=1;i<X.size();i++)
		for(int j=1;j<Y.size();j++)
			if(vis[i][j]!=2)
				ans+=1ll*(X[i]-X[i-1])*(Y[j]-Y[j-1]);
	cout<<ans;
}