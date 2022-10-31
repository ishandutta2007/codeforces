#include <bits/stdc++.h>
using namespace std;

bool used[305*305];
string s[305];
int n,m;
bool t;
vector<int> v[305*305];
void dfs(int x,int p){
    used[x]=1;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (to!=p && used[to]==1) t=true;
        if (used[to]==0) dfs(to,x);
    }
    used[x]=2;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>s[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=0;j<m;++j){
            if (s[i][j]==s[i+1][j]) v[(i-1)*m+j].push_back(i*m+j);
            if (s[i][j]==s[i-1][j]) v[(i-1)*m+j].push_back((i-2)*m+j);
            if (s[i][j]==s[i][j+1]) v[(i-1)*m+j].push_back((i-1)*m+j+1);
            if (s[i][j]==s[i][j-1]) v[(i-1)*m+j].push_back((i-1)*m+j-1);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (used[(i-1)*m+j]==0){
                dfs((i-1)*m+j,-1);
                if (t==true){
                    cout<<"Yes";
                    return 0;
                }
            }
        }
    }
    cout<<"No";
}