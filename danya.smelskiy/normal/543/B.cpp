#include <bits/stdc++.h>
using namespace std;


int n,m;
int depth[3005][3005];
int q[3005];
vector<int> v[3005];
int s1,t1,l1,s2,t2,l2;

inline void bfs(int x) {
    for (int i=1;i<=n;++i)
        depth[x][i]=1e9;
    depth[x][x]=0;
    int r=1;
    q[r]=x;
    for (int i=1;i<=r;++i) {
        int y=q[i];
        for (int j=0;j<v[y].size();++j) {
            int to=v[y][j];
            if (depth[x][to]>depth[x][y]+1) {
                depth[x][to]=depth[x][y]+1;
                q[++r]=to;
            }
        }
    }
}

void build() {
    for (int i=1;i<=n;++i)
        bfs(i);
}

inline int solve() {
    int res=-1;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int ll1=depth[s1][i]+depth[i][j]+depth[j][t1];
            if (ll1>l1) continue;
            int ll2=depth[s2][i]+depth[i][j]+depth[j][t2];
            if (ll2>l2) continue;
            res=max(res,m-(depth[s1][i]+depth[s2][i]+depth[j][t1]+depth[j][t2]+depth[i][j]));
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;
    build();
    int res=solve();
    swap(s2,t2);
    res=max(res,solve());
    if (depth[s1][t1]<=l1 && depth[s2][t2]<=l2) res=max(res,m-depth[s1][t1]-depth[s2][t2]);
    cout<<res;
}