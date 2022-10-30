#include <bits/stdc++.h>
using namespace std;



bool used[1000005];
int clr[1000005];
long long ans;
int n,m,s;
vector<int> q;
vector<pair<int,long long > > v[1000005],v2[1000005];
long long dp[1000005];
vector<int> vv[1000005];
long long dp1[1000005];
int x,y,z;
int all;
int sz;
long long last;
long long p[100005];
long long pp[100005];
void dfs1(int x){
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (used[to]==false) dfs1(to);
    }
    q.push_back(x);
}
void dfs2(int x,int y){
    clr[x]=y;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (clr[to]==0) dfs2(to,y);
    }
}
void dfs3(int x){
    used[x]=true;
    for (int i=0;i<v2[x].size();++i) {
        int to=v2[x][i].first;
        if (used[to]==false) dfs3(to);
    }
    q.push_back(x);
}
inline long long get(long long x){
    if (x==0) return 0;
    long long l=1;
    long long r=sz;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (p[mid]<=x) l=mid;
        else r=mid;
    }
    if (p[r]<=x) l=r;
    long long res=0;
    res=((l+1)*x-pp[l]);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;;++i) {
        last+=(long long)i;
        p[i]=last;
        pp[i]=pp[i-1]+last;
        if (p[i]>=1e8) break;
        sz=i;
    }
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        vv[y].push_back(x);
    }
    for (int i=1;i<=n;++i) if (used[i]==false) dfs1(i);
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        int x=q[i];
        if (clr[x]==0) dfs2(x,++all);
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j].first;
            if (clr[to]!=clr[i]) {
                v2[clr[i]].push_back(make_pair(clr[to],v[i][j].second));
                continue;
            }
            dp1[clr[i]]+=get(v[i][j].second);
        }
    }
    q.clear();
    cin>>s;
    memset(used,false,sizeof(used));
    dfs3(clr[s]);
    dp[clr[s]]=dp1[clr[s]];
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        int x=q[i];
        ans=max(ans,dp[x]);
        for (int j=0;j<v2[x].size();++j) {
            int to=v2[x][j].first;
            dp[to]=max(dp[to],dp[x]+(long long)v2[x][j].second+dp1[to]);
        }
    }
    cout<<ans;
}