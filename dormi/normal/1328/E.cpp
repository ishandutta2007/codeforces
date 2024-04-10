#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
int depth[MAXN];
int lift[18][MAXN];
void dfs(int loc, int parent, int dep){
    lift[0][loc]=parent;
    depth[loc]=dep;
    for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
}
int n,m;
void ml(){
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++)lift[i][j]=lift[i-1][lift[i-1][j]];
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<=17;i++){
        if(diff&(1<<i)){
            a=lift[i][a];
        }
    }
    if(a==b)return a;
    for(int i=17;i>=0;i--){
        if(lift[i][a]!=lift[i][b]){
            a=lift[i][a],b=lift[i][b];
        }
    }
    return lift[0][a];
}
vector<int> nodes;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    ml();
    while(m--){
        cin>>a;
        nodes.clear();
        for(int i=0;i<a;i++){
            cin>>b;
            nodes.push_back(b);
        }
        sort(nodes.begin(),nodes.end(),[&](auto lhs, auto rhs){
            return depth[lhs]<depth[rhs];
        });
        if(a==1){
            printf("YES\n");
            continue;
        }
        int node=lift[0][nodes.back()];
        bool work=true;
        for(int i=0;i<a;i++){
            assert(depth[nodes[i]]<=depth[node]+1);
            if(nodes[i]!=1&&lca(lift[0][nodes[i]],node)!=lift[0][nodes[i]]){
                work=false;
                break;
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}