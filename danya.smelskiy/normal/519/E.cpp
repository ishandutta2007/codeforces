#include <bits/stdc++.h>
using namespace std;

int kol[100005];
int timer;
int tin[100005];
int tout[100005];
int depth[100005];
vector<int> v[100005];
int dp[100005][18];
int n,x,y,m;

void dfs(int x,int y,int z){
    kol[x]=1;
    depth[x]=z;
    tin[x]=++timer;
    dp[x][0]=y;
    for (int i=1;i<=17;++i)
        dp[x][i]=dp[dp[x][i-1]][i-1];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x,z+1);
        kol[x]+=kol[to];
    }
    tout[x]=++timer;
}
inline bool is_pred(int x,int y){
    return tin[x]<=tin[y] && tout[x]>=tout[y];
}
inline int getlca(int x,int y){
    if (depth[x]>depth[y]) swap(x,y);
    if (is_pred(x,y)) return x;
    for (int i=17;i>=0;--i)
        if (!(is_pred(dp[x][i],y))) x=dp[x][i];
    return dp[x][0];
}
inline int dist(int x,int y){
    return depth[x]+depth[y]-2*depth[getlca(x,y)];
}
inline int getkth(int x,int k){
    for (int i=17;i>=0;--i)
    if ((1<<i)<=k) {
        k-=(1<<i);
        x=dp[x][i];
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    tin[0]=0;
    tout[0]=1e9;
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,0);
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        if (x==y) {
            cout<<n<<'\n';
            continue;
        }
        int d=dist(x,y);
        if (d%2==1) {
            cout<<0<<'\n';
            continue;
        }
        if (depth[x]==depth[y]) {
            int c=getlca(x,y);
            int len=depth[x]-depth[c]-1;
            x=getkth(x,len);
            y=getkth(y,len);
            cout<<n-kol[x]-kol[y]<<'\n';
            continue;
        }
        if (depth[x]<depth[y]) swap(x,y);
        d/=2;
        y=getkth(x,d-1);
        x=getkth(x,d);
        cout<<kol[x]-kol[y]<<'\n';
    }
}