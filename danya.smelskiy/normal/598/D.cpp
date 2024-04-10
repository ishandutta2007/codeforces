#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s[1005];
int sz;
int x,y;
bool used[1005][1005];
int t[1005][1005];
int ans[1000005];
void dfs(int x,int y,int z){
    if (used[x][y]) return;
    if (y<1 || y>m) return;
    if (x<1 || x>n) return;
    if (s[x][y-1]=='*') return;
    t[x][y]=z;
    used[x][y]=true;
    if (x>1 && s[x-1][y-1]=='*') ++ans[z];
    if (x<n && s[x+1][y-1]=='*') ++ans[z];
    if (y>1 && s[x][y-2]=='*') ++ans[z];
    if (y<m && s[x][y]=='*') ++ans[z];
    dfs(x-1,y,z);
    dfs(x+1,y,z);
    dfs(x,y-1,z);
    dfs(x,y+1,z);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>s[i];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (s[i][j-1]=='.' && used[i][j]==false) {
                ++sz;
                dfs(i,j,sz);
        }
    for (int i=1;i<=k;++i){
        cin>>x>>y;
        cout<<ans[t[x][y]]<<'\n';
    }
}