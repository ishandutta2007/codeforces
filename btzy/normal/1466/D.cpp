#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100000;
int weights[MAXN];
int edges[MAXN];
struct cmp{
    bool operator()(int a, int b) const noexcept {
        return weights[a]<weights[b];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        long long ans=0;
        for(int i=0;i<n;++i){
            cin>>weights[i];
            edges[i]=0;
            ans+=weights[i];
        }
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            --u;--v;
            ++edges[u];
            ++edges[v];
        }
        priority_queue<int,vector<int>,cmp> pq;
        for(int i=0;i<n;++i){
            if(edges[i]>1){
                pq.push(i);
            }
        }
        cout<<ans;
        while(!pq.empty()){
            int x=pq.top();
            ans+=weights[x];
            --edges[x];
            if(edges[x]<=1){
                pq.pop();
            }
            cout<<' '<<ans;
        }
        cout<<'\n';
    }
}