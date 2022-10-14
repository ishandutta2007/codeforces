#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> adj1[MN],adj2[MN];
int depth[MN],st[MN],en[MN],et;
void dfs2(int loc, int parent){
    st[loc]=et++;
    depth[loc]=depth[parent]+1;
    for(auto x:adj2[loc])if(x!=parent)dfs2(x,loc);
    en[loc]=et-1;
}
set<pii> nodes;
int ans=0;
void dfs1(int loc, int parent){
    bool inserted=false;
    pii removed={-1,-1};
    if(!sz(nodes)||nodes.lower_bound({st[loc],loc})==nodes.end()||nodes.lower_bound({st[loc],loc})->first>en[loc]){
        nodes.insert({st[loc],loc});
        inserted=true;
        auto te=nodes.lower_bound({st[loc],loc});
        if(te!=nodes.begin()&&en[prev(te,1)->second]>=st[loc]){
            removed=*prev(te,1);
            nodes.erase(prev(te,1));
        }
    }
    ans=max(ans,sz(nodes));
    for(auto x:adj1[loc]){
        if(x!=parent)dfs1(x,loc);
    }
    if(inserted)nodes.erase({st[loc],loc});
    if(removed.first!=-1)nodes.insert(removed);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++)adj1[i]=vector<int>(),adj2[i]=vector<int>();
        for(int i=1;i<n;i++){
            cin>>a;
            b=i+1;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for(int i=1;i<n;i++){
            cin>>a;
            b=i+1;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        dfs2(1,0);
        nodes=set<pii>(),ans=0;
        dfs1(1,0);
        printf("%d\n",ans);
    }
    return 0;
}