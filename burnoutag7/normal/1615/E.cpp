#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> g[200005];
priority_queue<int> t[200005];

struct cmp{
    bool operator()(const int &lhs,const int &rhs)const{
        if(t[lhs].size()!=t[rhs].size())return t[lhs].size()<t[rhs].size();
        return lhs<rhs;
    }
};

int dfs(int x,int p){
    set<int,cmp> s;
    for(int y:g[x])if(y!=p){
        s.emplace(dfs(y,x));
    }
    if(s.empty()){
        t[x].emplace(2);
        return x;
    }
    while(s.size()>1){
        int a=*s.begin();
        s.erase(s.begin());
        int b=*s.begin();
        s.erase(s.begin());
        while(!t[a].empty()){
            t[b].emplace(t[a].top());
            t[a].pop();
        }
        s.emplace(b);
    }
    int res=*s.begin();
    int val=t[res].top();
    t[res].pop();
    val++;
    t[res].emplace(val);
    t[res].emplace(1);
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int res=dfs(1,-1);
    typedef long long ll;
    ll ans=(ll)-n*n;
    int psum=0;
    for(int i=1;i<=k;i++){
        psum+=t[res].top();
        t[res].pop();
        int r=i,b=i-(psum-n);
        ll cur=(ll)(n-r-b)*(r-b);
        if(b>=n/2){
            for(int c=max(0,n/2-2);c<=min(n/2+2,b);c++){
                cur=min(cur,(ll)(n-r-c)*(r-c));
            }
        }
        ans=max(ans,cur);
    }
    cout<<ans;

    return 0;
}