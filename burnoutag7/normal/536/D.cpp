#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int,int>> g[2005];

void dijkstra(const int& s,ll* d,const int& n){
    memset(d+1,0x3f,n<<3);
    d[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.emplace(0,s);
    while(!pq.empty()){
        int x=pq.top().second;
        ll cd=pq.top().first;
        pq.pop();
        if(cd>d[x])continue;
        for(const pair<int,int>& e:g[x])if(d[e.first]>cd+e.second){
            pq.emplace(d[e.first]=cd+e.second,e.first);
        }
    }
}

int n,m,s,t,w[2005],cs,ct,c[2005][2005];
ll dp[2005][2005][2],a[2005][2005],ds[2005],dt[2005];
map<ll,int> ms,mt;

inline ll sum(const int& u,const int& d,const int& l,const int& r){
    return a[d][r]+a[u-1][l-1]-a[u-1][r]-a[d][l-1];
}

inline int cnt(const int& u,const int& d,const int& l,const int& r){
    return c[d][r]+c[u-1][l-1]-c[u-1][r]-c[d][l-1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        static int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    dijkstra(s,ds,n);
    dijkstra(t,dt,n);
    for(int i=1;i<=n;i++)ms[ds[i]]=mt[dt[i]]=0;
    for(pair<const ll,int>& p:ms)p.second=++cs;
    for(pair<const ll,int>& p:mt)p.second=++ct;

    for(int i=1;i<=n;i++){
        a[ms[ds[i]]][mt[dt[i]]]+=w[i];
        c[ms[ds[i]]][mt[dt[i]]]++;
    }
    for(int i=1;i<=cs;i++)for(int j=1;j<=ct;j++){
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
    }

    for(int i=cs;i>=1;i--){
        for(int j=ct;j>=1;j--){
            if(cnt(i,i,j,ct)){
                dp[i][j][0]=sum(i,i,j,ct)+max(dp[i+1][j][0],-dp[i+1][j][1]);
            }else dp[i][j][0]=dp[i+1][j][0];
            if(cnt(i,cs,j,j)){
                dp[i][j][1]=sum(i,cs,j,j)+max(dp[i][j+1][1],-dp[i][j+1][0]);
            }else dp[i][j][1]=dp[i][j+1][1];
        }
    }
    cout<<(dp[1][1][0]==0?"Flowers\n":(dp[1][1][0]>0?"Break a heart\n":"Cry\n"));

    return 0;
}