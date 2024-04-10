#include <bits/stdc++.h>
using namespace std;



vector<pair<int,long long> > v[100005];
int sz1[100005];
int sz2[100005];
int pred[100005],p[100005];
long long dp[100005][2];
int n,m;
pair<long long,int> q[100005];

long long mx[100005];
long long dfs1(int x,int y){
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        long long len=dfs1(to,x)+v[x][i].second;
        if (len>=dp[x][0]) {
            dp[x][1]=dp[x][0]; dp[x][0]=len;
        } else if (len>dp[x][1]) {
            dp[x][1]=len;
        }
    }
    return dp[x][0];
}
void dfs2(int x,int y,long long len){
    mx[x]=max(dp[x][0],len);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        if (dp[to][0]+v[x][i].second==dp[x][0]) dfs2(to,x,max(len,dp[x][1])+v[x][i].second);
        else dfs2(to,x,max(len,dp[x][0])+v[x][i].second);
    }
}
void dfs(int x,int y){
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        dfs(to,x);
    }
}
inline void init(){
    for (int i=1;i<=n;++i) {
        p[i]=i;
        sz1[i]=1;
        sz2[i]=1;
    }
}
int get(int x){
    if (x==p[x]) return x;
    else return p[x]=get(p[x]);
}
inline void unite(int x,int y){
    if (sz1[x]>sz1[y]) swap(x,y);
    p[x]=y;
    sz1[y]+=sz1[x];
    sz2[y]+=sz2[x];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        long long z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs1(1,-1);
    dfs2(1,-1,0);
    int root;
    long long mn=1e18;
    for (int i=1;i<=n;++i) if (mx[i]<mn) {
        mn=mx[i];
        root=i;
    }
    dfs(root,-1);
    for (int i=1;i<=n;++i)
        q[i]=make_pair(mx[i],i);
    sort(q+1,q+n+1);
    cin>>m;
    for (int i=1;i<=m;++i) {
        long long l;
        cin>>l;
        init();
        int ans=0;
        for (int j=n,last=n;j>0;--j) {
            int x=q[j].second;
            for (int k=0;k<v[x].size();++k) {
                int to=v[x][k].first;
                if (to==pred[x]) continue;
                unite(get(x),get(to));
            }
            while (last>j && mx[q[j].second]<mx[q[last].second]-l) {
                --sz2[get(q[last].second)];
                --last;
            }
            ans=max(ans,sz2[get(x)]);
        }
        cout<<ans<<'\n';
    }
}