#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > v[105];
bool used[105][105][2][27];
bool dp[105][105][2][27];


bool dfs(int x,int y,int xx,int yy) {
    if (used[x][y][xx][yy]) return dp[x][y][xx][yy];
    used[x][y][xx][yy]=true;
    if (xx==0) {
        for (int i=0;i<v[x].size();++i) {
            if (v[x][i].second>=yy && !dfs(v[x][i].first,y,1,v[x][i].second)) return dp[x][y][xx][yy]=true;
        }
        return dp[x][y][xx][yy]=false;
    }
    for (int i=0;i<v[y].size();++i) {
        if (v[y][i].second>=yy && !dfs(x,v[y][i].first,0,v[y][i].second)) return dp[x][y][xx][yy]=true;
    }
    return dp[x][y][xx][yy]=false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        char c;
        cin>>c;
        int z=(c-'a')+1;
        v[x].push_back(make_pair(y,z));
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (dfs(i,j,0,0)) cout<<"A";
            else cout<<"B";
        }
        cout<<endl;
    }
}