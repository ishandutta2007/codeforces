#include <bits/stdc++.h>
using namespace std;
long long n,ans;
vector<int> v[10001];
pair<int,int> a[10001];
bool used[100001];
void dfs(int x){
    used[x]=true;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        if (i!=j && (a[i].first==a[j].first || a[i].second==a[j].second)) {
            v[i].push_back(j);
            v[j].push_back(i);
        }
    for (int i=1;i<=n;++i)
    if (used[i]==false){
        ++ans;
        dfs(i);
    }
    cout<<ans-1;
}