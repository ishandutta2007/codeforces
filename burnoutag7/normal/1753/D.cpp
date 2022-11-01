#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,p,q,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
vector<ll> d[300005];
string g[300005];

int gpx(int x,int y){
    return g[x][y]=='U'?x+1:g[x][y]=='D'?x-1:x;
}

int gpy(int x,int y){
    return g[x][y]=='L'?y+1:g[x][y]=='R'?y-1:y;
}

bool in(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>p>>q;
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pq;
    for(int i=1;i<=n;i++){
        g[i].resize(m+1);
        d[i].resize(m+1,1e18);
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='.'){
                d[i][j]=0;
                pq.emplace(0,pair<int,int>{i,j});
            }
        }
    }
    while(!pq.empty()){
        int x=pq.top().second.first,y=pq.top().second.second;
        ll cd=pq.top().first;
        pq.pop();
        if(cd>d[x][y])continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(in(nx,ny)&&g[nx][ny]!='#'&&g[nx][ny]!='.'){
                int px=gpx(nx,ny),py=gpy(nx,ny),cost=x==nx&&nx==px||y==ny&&ny==py?q:p;
                if(d[px][py]>cd+cost){
                    pq.emplace(d[px][py]=cd+cost,pair<int,int>{px,py});
                }
            }
        }
    }
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<n)ans=min(ans,d[i][j]+d[i+1][j]);
            if(j<m)ans=min(ans,d[i][j]+d[i][j+1]);
        }
    }
    if(ans==1e18)ans=-1;
    cout<<ans<<'\n';

    return 0;
}