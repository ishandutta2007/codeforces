#include <bits/stdc++.h>
using namespace std;




int n,m;
bool used[505][505];
string s[505];
vector<pair<char,pair<int,int> > > ans;



void dfs(int x,int y,bool t=false) {
    if (used[x][y] || x<1 || x>n || y<1 || y>m || s[x][y]!='.') return;
    ans.push_back(make_pair('B',make_pair(x,y)));
    used[x][y]=true;
    dfs(x+1,y,true);
    dfs(x-1,y,true);
    dfs(x,y-1,true);
    dfs(x,y+1,true);
    if (t) {
        ans.push_back(make_pair('D',make_pair(x,y)));
        ans.push_back(make_pair('R',make_pair(x,y)));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j)
            if (s[i][j]=='.' && !used[i][j]) dfs(i,j);
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<'\n';
}