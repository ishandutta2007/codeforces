#include <bits/stdc++.h>
using namespace std;

long long n,m,x,y,ans;
vector<int> v[1000001];
int a[1000001];
bool used[100001];
void dfs(int i,int sum){
    sum+=a[i];
    if (a[i]==0) sum=0;
    used[i]=true;
    if (sum>m) return;
    bool t=false;
    for (int j=0;j<v[i].size();++j)
    if (used[v[i][j]]==false){
        t=true;
        dfs(v[i][j],sum);
    }
    if (t==false) { ++ans; }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n-1;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans;
}