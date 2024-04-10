#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<tuple<int,int,int>>> adj(n+1);
    vector<tuple<int,int,int>> edg(m+1);
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        edg[i]=make_tuple(u,v,w);
        adj[u].push_back(make_tuple(v,w,i));adj[v].push_back(make_tuple(u,w,i));
    }
    auto dijk=[&](int st)->vector<long long>{
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long>dis(n+1,-1);dis[st]=0;pq.push(make_pair(0,st));
        while(!pq.empty()){
            pair<long long,int> u=pq.top();pq.pop();
            if(dis[u.second]!=u.first)continue;
            for(auto&x:adj[u.second]){
                int v=get<0>(x);long long w=u.first+get<1>(x);
                if(dis[v]==-1||w<dis[v]){
                    dis[v]=w;pq.push(make_pair(w,v));
                }
            }
        }
        return dis;
    };
    vector<long long> d[2];d[0]=dijk(1);d[1]=dijk(n);
    vector<int> vpth,epth,tvpth,tepth;
    vector<bool> vis(n+1);
    function<void(int)> dfs=[&](int u)->void{
        tvpth.push_back(u);
        if(u==n){
            vpth=tvpth;epth=tepth;
        }
        vis[u]=1;
        for(auto&x:adj[u]){
            int v=get<0>(x),w=get<1>(x);
            if(d[0][v]==d[0][u]+w&&!vis[v]){
                tepth.push_back(get<2>(x));
                dfs(v);
                tepth.pop_back();
            }
        }
        tvpth.pop_back();
    };dfs(1);
    auto proc=[&](vector<int> pth,vector<long long>&dis)->vector<int>{
        vector<bool> vis(n+1,0);for(int x:pth)vis[x]=1;
        vector<int> l(n+1,-1);
        for(int i=0;i<pth.size();i++){
            int u=pth[i];vis[u]=0;
            queue<int> q;q.push(u);
            l[u]=i;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(auto&x:adj[u]){
                    int v=get<0>(x);
                    if(dis[v]==dis[u]+get<1>(x)&&!vis[v]&&l[v]==-1){
                        l[v]=i;
                        q.push(v);
                    }
                }
            }
        }
        return l;
    };
    vector<int> l[2];l[0]=proc(vpth,d[0]);
    vector<int> rvpth=vpth;reverse(rvpth.begin(),rvpth.end());l[1]=proc(rvpth,d[1]);
    vector<bool> inp(m+1);for(auto x:epth)inp[x]=1;
    vector<vector<pair<long long,int>>> chg(vpth.size());
    for(int i=1;i<=m;i++){
        if(!inp[i]){
            int u[2]={get<0>(edg[i]),get<1>(edg[i])};
            for(int rv=0;rv<2;rv++){
                if(l[0][u[0]]!=-1&&l[1][u[1]]!=-1){
                    int li=l[0][u[0]],ri=vpth.size()-1-l[1][u[1]];
                    if(li<ri){
                        long long w=d[0][u[0]]+d[1][u[1]]+get<2>(edg[i]);
                        chg[li].push_back(make_pair(w,ri));
                    }
                }
                swap(u[0],u[1]);
            }
        }
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    vector<long long> ans(m+1,d[0][n]);
    for(int i=0;i<epth.size();i++){
        for(auto&x:chg[i])pq.push(x);
        while(!pq.empty()&&pq.top().second<=i)pq.pop();
        if(pq.empty()){
            ans[epth[i]]=-1;
        }else{
            ans[epth[i]]=pq.top().first;
        }
    }
    while(q--){
        int t,x;cin>>t>>x;
        long long cans=LLONG_MAX;
        int u[2]={get<0>(edg[t]),get<1>(edg[t])};
        for(int rv=0;rv<2;rv++,swap(u[0],u[1]))if(d[0][u[0]]!=-1&&d[1][u[1]]!=-1)cans=min(cans,d[0][u[0]]+d[1][u[1]]+x);
        if(inp[t]){
            if(ans[t]!=-1)cans=min(cans,ans[t]);
        }else cans=min(cans,d[0][n]);
        cout<<cans<<'\n';
    }
    return 0;
}