#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=200005,mod=998244353;

const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m;
vector<vector<char>> tab;

bool ingrid(int x, int y){return x>=0&&x<n&&y>=0&&y<m;}

bool good(int x, int y){
    if(!ingrid(x,y)) return 0;
    rep(i,0,4){
        int nx=x+dx[i],ny=y+dy[i];
        if(ingrid(nx,ny)&&tab[nx][ny]=='#') return 0;
    }
    return 1;
}

vector<vector<int>> dis;
vector<vector<pii>> par;
vector<vector<bool>> vis;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        tab.resize(n);
        for(auto& vec: tab) vec.resize(m);
        for(auto& vec: tab) for(auto& c: vec) cin >> c;
        dis.resize(n);
        for(auto& vec: dis) vec.resize(m);
        for(auto& vec: dis) for(auto& i: vec) i=4e18;
        vis.resize(n);
        for(auto& vec: vis){
            vec.resize(m);
            rep(j,0,m) vec[j]=0;
        }
        par.resize(n);
        for(auto& vec: par){
            vec.resize(m);
            for(auto& i: vec) i={-1,-1};
        }
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        rep(i,0,n) if(good(i,0)){
            if(tab[i][0]=='#') dis[i][0]=0,pq.push({0,i,0});
            else dis[i][0]=1,pq.push({1,i,0});
        }
        while(!pq.empty()){
            auto [d,x,y]=pq.top(); pq.pop();
            if(vis[x][y]) continue;
            vis[x][y]=1;
            for(auto nx: {x-1,x+1}) for(auto ny: {y-1,y+1}) if(good(nx,ny)){
                int ndis=d+(tab[nx][ny]=='#'?0:1);
                if(ndis<dis[nx][ny]){
                    dis[nx][ny]=ndis;
                    pq.push({ndis,nx,ny});
                    par[nx][ny]={x,y};
                }
            }
        }
        int minn=4e18,x=-1,y=-1;
        rep(i,0,n) if(dis[i][m-1]<minn){
            minn=dis[i][m-1];
            x=i,y=m-1;
        }
        if((!ingrid(x,y))||dis[x][y]>1e18){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        while(ingrid(x,y)){
            tab[x][y]='#';
            pii p=par[x][y];
            x=p.first,y=p.second;
        }
        rep(i,0,n){
            rep(j,0,m) cout << tab[i][j];
            cout << "\n";
        }
    }
}