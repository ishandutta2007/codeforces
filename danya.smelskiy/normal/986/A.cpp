#include <bits/stdc++.h>
using namespace std;


int n,m,k,s;
int a[100005];
vector<int> v[100005];
int depth[102][100005];
int q[100005];
int p[10005];
int sz;
int x,y;
vector<int> qq[10005];

inline void solve(int x) {
    for (int i=1;i<=n;++i) {
        depth[x][i]=1e9;
    }
    sz=0;
    for (int i=0;i<qq[x].size();++i) {
        int y=qq[x][i];
        q[++sz]=y;
        depth[x][y]=0;
    }
    for (int i=1;i<=sz;++i) {
        y=q[i];
        for (int j=0;j<v[y].size();++j) {
            int to=v[y][j];
            if (depth[x][to]>depth[x][y]+1) {
                depth[x][to]=depth[x][y]+1;
                ++sz;
                q[sz]=to;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>s;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        qq[a[i]].push_back(i);
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=k;++i) {
        solve(i);
    }
    int cur=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=k;++j)
            p[j]=depth[j][i];
        sort(p+1,p+k+1);
        cur=0;
        for (int j=1;j<=s;++j)
            cur+=p[j];
        cout<<cur<<" ";
    }
}