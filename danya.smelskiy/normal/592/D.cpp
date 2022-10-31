#include <bits/stdc++.h>
using namespace std;


int n,m,x,y;
bool used[2000005];
vector<int> v[2000005];
int dp[2000005];
int d1[2000005];
int d2[2000005];
int p1[2000005];
int p2[2000005];
int ans1,ans2,ans3;
void dfs(int x,int y){
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y || used[to]==false) continue;
        dfs(to,x);
        int l=1,r=to;
        if (d1[to]) {
            l=d1[to]+1;
        }
        if (l>d2[x]) {
            d2[x]=l;
            p2[x]=r;
            if (d2[x]>d1[x]) {
                swap(d2[x],d1[x]);
                swap(p1[x],p2[x]);
            }
        }
    }
}
void dfs1(int x,int y){
    int kol=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs1(to,x);
        if (used[to]) ++kol;
    }
    if (kol) used[x]=true;
}
void dfs2(int x,int y){
    ++ans2;
    if (y!=-1) {
        dp[x]=dp[y]+1;
        if (p1[y]==x) dp[x]=max(dp[x],d2[y]+1);
        else dp[x]=max(dp[x],d1[y]+1);
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y || used[to]==false) continue;
        dfs2(to,x);
    }
    if (max(dp[x],d1[x])>ans3 || (max(dp[x],d1[x])==ans3 && x<ans1)) {
        ans3=max(dp[x],d1[x]);
        ans1=x;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int last;
    for (int i=1;i<=m;++i) {
        cin>>last;
        used[last]=true;
    }
    dfs1(last,-1);
    dfs(last,-1);
    ans1=last;
    dfs2(last,-1);
    cout<<ans1<<'\n';
    cout<<(ans2-1)*2-ans3;
}