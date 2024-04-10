#include<bits/stdc++.h>
using namespace std;

int n,fae[100005];
long long s,wt[100005];
vector<pair<int,int>> g[100005];

void dfs(const int &x,const int &p){
    wt[x]=g[x].size()==1;
    for(const pair<int,int> &e:g[x])if(e.first!=p){
        dfs(e.first,x);
        wt[x]+=wt[e.first];
        s+=wt[e.first]*(fae[e.first]=e.second);
    }
}

void mian(){
    cin>>n>>s;
    s=-s;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dfs(1,-1);
    priority_queue<long long> pq;
    for(int i=2;i<=n;i++){
        while(fae[i]){
            pq.emplace((fae[i]+1>>1)*wt[i]);
            fae[i]>>=1;
        }
    }
    int ans=0;
    while(s>0){
        s-=pq.top();
        pq.pop();
        ans++;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}