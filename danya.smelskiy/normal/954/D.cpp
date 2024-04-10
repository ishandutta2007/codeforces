#include <bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<int> v[1005];
int ans;
bool f[1005][1005];
int d[2][1005];
int q[1005];

void bfs(int x,int y) {
    for (int i=1;i<=n;++i)
        d[x][i]=1e9;
    d[x][y]=0;
    int sz=1;
    q[sz]=y;
    for (int i=1;i<=sz;++i) {
        y=q[i];
        for (int j=0;j<v[y].size();++j) {
            int to=v[y][j];
            if (d[x][to]>d[x][y]+1) {
                q[++sz]=to;
                d[x][to]=d[x][y]+1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        f[x][y]=f[y][x]=true;
    }
    bfs(0,s);
    bfs(1,t);
    int len;
    int len2=d[0][t];
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) if (!f[i][j]) {
            len=d[0][i]+d[1][j]+1;
            len=min(len,d[0][j]+d[1][i]+1);
            if (len>=len2) ++ans;
        }
    }
    cout<<ans;
}