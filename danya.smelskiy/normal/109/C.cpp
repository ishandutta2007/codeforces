#include <bits/stdc++.h>
using namespace std;


long long dp[100005];
long long dp2[100005];
int n,x,y,z;
vector<pair<int,int> > v[100005];
long long ans;
long long kol[100005];

inline bool check(int x){
    while (x) {
        if (x%10!=7 && x%10!=4) return false;
        x/=10;
    }
    return true;
}
void dfs1(int x,int y){
    kol[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        dfs1(to,x);
        kol[x]+=kol[to];
        if (check(v[x][i].second)) dp[x]+=kol[to];
        else dp[x]+=dp[to];
    }
    dp2[x]=dp[x];
}
void dfs2(int x,int y,int z){
    if (y!=-1) {
        if (check(z)) dp2[x]+=n-kol[x];
        else dp2[x]+=dp2[y]-dp[x];
    }
    ans+=(dp2[x])*(dp2[x]-1);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        dfs2(to,x,v[x][i].second);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs1(1,-1);
    dfs2(1,-1,0);
    cout<<ans;
}