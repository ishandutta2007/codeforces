#include <bits/stdc++.h>
using namespace std;
long long n,x,ans;
bool used[2001];
vector<int> v[2001];
void dfs(int x,long long y){
    ans=max(ans,y);
    for (int j=0;j<v[x].size();++j)
        dfs(v[x][j],y+1);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==-1) used[i]=true;
        else
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i){
        if (used[i]==true) dfs(i,1);
    }
    cout<<ans;
}