#include <bits/stdc++.h>
using namespace std;


bool used[100005];
vector<int> v[100005];
int kk;
bool dp1[100005];
int dp2[100005];
int n,m;
int kol[100005];
void dfs(int x,int y=-1) {
    used[x]=true;
    ++kk;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs(to,x);
    }
}
void add(int x,int y){
    for (int i=n;i>=x;--i)
    if (dp1[i-x]) {
        if (dp1[i]) dp2[i]=min(dp2[i],dp2[i-x]+y);
        else dp2[i]=dp2[i-x]+y;
        dp1[i]=true;
    }
    dp2[x]=min(dp2[x],y-1);
}
inline bool check(int x){
    while (x) {
        if (x%10!=4 && x%10!=7) return false;
        x/=10;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dp1[0]=true;
    for (int i=1;i<=n;++i) if (used[i]==false) {
        kk=0;
        dfs(i);
        ++kol[kk];
    }
    for (int i=1;i<=n;++i) if (kol[i]) {
        int sz=1;
        while (sz<=kol[i]) {
            add(sz*i,sz);
            kol[i]-=sz;
            sz*=2;
        }
        if (kol[i]) add(kol[i]*i,kol[i]);
    }
    int ans=1e9;
    for (int i=1;i<=n;++i)
        if (check(i) && dp1[i]) {
            ans=min(ans,dp2[i]);
        }
    cout<<(ans==1e9 ? -1 : ans);
}