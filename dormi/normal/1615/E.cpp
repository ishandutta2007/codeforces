#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<int> adj[MN];
vector<int> leaves;
int parent[MN];
int depth[MN];
int st[MN];
int et=0;
int sparse[__lg(2*MN)+1][2*MN];
void dfs(int loc, int par){
    depth[loc]=depth[par]+1;
    parent[loc]=par;
    st[loc]=et;
    sparse[0][et++]=loc;
    if(par!=0)adj[loc].erase(find(adj[loc].begin(),adj[loc].end(),par));
    for(auto x:adj[loc]){
        dfs(x,loc);
        sparse[0][et++]=loc;
    }
    if(sz(adj[loc])==0)leaves.push_back(loc);
}
int mh(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ms(){
    for(int i=1;i<=__lg(et);i++){
        for(int j=0;j+(1<<i)<=et;j++){
            sparse[i][j]=mh(sparse[i-1][j],sparse[i-1][j+(1<<(i-1))]);
        }
    }
}
int getlca(int a, int b){
    a=st[a],b=st[b];
    if(a>b)swap(a,b);
    int k=__lg(b-a+1);
    return mh(sparse[k][a],sparse[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,a,b;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    ms();
    bool playforwin=(k>=sz(leaves));
    if(!playforwin){
        set<pii> teleaves;
        set<pair<int,pii>> values;
        auto get=[&](auto it){
            int best=depth[it->second];
            if(it!=teleaves.begin()){
                best=min(best,depth[it->second]-depth[getlca(it->second,prev(it,1)->second)]);
            }
            if(next(it,1)!=teleaves.end()){
                best=min(best,depth[it->second]-depth[getlca(it->second,next(it,1)->second)]);
            }
            return pair<int,pii>{best,*it};
        };
        for(int i=0;i<sz(leaves);i++){
            teleaves.insert({i,leaves[i]});
        }
        for(auto it=teleaves.begin();it!=teleaves.end();it++){
            values.insert(get(it));
        }
        int bluetake=0;
        for(int i=0;i<sz(leaves)-k;i++){
            bluetake+=values.begin()->first;
            auto it=teleaves.find(values.begin()->second);
            values.erase(values.begin());
            if(it!=teleaves.begin()){
                values.erase(get(prev(it,1)));
            }
            if(next(it,1)!=teleaves.end()){
                values.erase(get(next(it,1)));
            }
            it++;
            teleaves.erase(prev(it,1));
            if(it!=teleaves.end()){
                values.insert(get(it));
            }
            if(it!=teleaves.begin()){
                values.insert(get(prev(it,1)));
            }
        }
        if(bluetake<=k){
            printf("%lli\n",ll(k-bluetake)*ll(n-k-bluetake));
            return 0;
        }
        else{//red playing to get smallest negative, this gives blue as little choice as possible
            ll best=LLONG_MAX;
            for(ll i=0;i<=bluetake;i++){
                best=min(best,ll(n-i-k)*ll(k-i));
            }
            printf("%lli\n",best);
            return 0;
        }
    }
    ll best=LLONG_MIN;
    for(ll i=sz(leaves);i<=k;i++){
        best=max(best,ll(i)*ll(n-i));
    }
    printf("%lli\n",best);
    return 0;
}