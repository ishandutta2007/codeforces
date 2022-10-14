#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int lca[17][MAXN];
int depth[MAXN];
int n;
void dfs(int loc, int parent, int dep){
    lca[0][loc]=parent;
    depth[loc]=dep;
    for(int x:matrix[loc]){
        if(x!=parent)dfs(x,loc,dep+1);
    }
}
void mlc(){
    for(int i=1;i<17;i++){
        for(int j=1;j<=n;j++){
            lca[i][j]=lca[i-1][lca[i-1][j]];
        }
    }
}
int getlca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    for(int i=0;i<17;i++)if(diff&(1<<i))a=lca[i][a];
    if(a==b)return a;
    for(int i=16;i>=0;i--)if(lca[i][a]!=lca[i][b]){
        a=lca[i][a];
        b=lca[i][b];
    }
    return lca[0][a];
}
int getdist(int a, int b){
    return depth[a]+depth[b]-2*depth[getlca(a,b)];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    mlc();
    int q;
    cin>>q;
    int x,y,k;
    while(q--){
        cin>>x>>y>>a>>b>>k;
        int normdist=getdist(a,b);
        if(normdist<=k&&normdist%2==k%2){
            printf("YES\n");
            continue;
        }
        int othdist=getdist(a,x)+1+getdist(b,y);
        if(othdist<=k&&othdist%2==k%2) {
            printf("YES\n");
            continue;
        }
        othdist=getdist(a,y)+1+getdist(b,x);
        if(othdist<=k&&othdist%2==k%2) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}