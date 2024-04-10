#include <bits/stdc++.h>
using namespace std;

bool used[100001];
vector<int> v[100001];
int n,x;
int ans;

void dfs(long long x){
    used[x]=true;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i)
    if (used[i]==false){
        dfs(i);
        ++ans;
    }
    cout<<ans;
}