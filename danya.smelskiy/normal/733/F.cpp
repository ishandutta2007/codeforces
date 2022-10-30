#include <bits/stdc++.h>
using namespace std;


struct st{
    long long a,b;
    int id,x,y;
};
st reb[300005];
bool used[300005];
vector<pair<int,long long> > v[300005];
long long dp[300005][21];
int pred[300005][21];
int p[300005];
long long all,mn,s,ans;
int pos;
int n,m;
int timer,tin[300005],tout[300005];
inline bool cmp(st x,st y){
    return x.a<y.a;
}
int get(int x){
    if (x==p[x]) return x;
    else return p[x]=get(p[x]);
}
void build_tree(){
    for (int i=1;i<=m;++i)
        used[i]=false;
    sort(reb+1,reb+m+1,cmp);
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=1;i<=n;++i)
        v[i].clear();
    all=0;
    mn=1e15;
    pos=0;
    for (int i=1;i<=m;++i) {
        int x=reb[i].x;
        int y=reb[i].y;
        x=get(x);
        y=get(y);
        if (x==y) continue;
        all+=reb[i].a;
        if (mn>reb[i].b) {
            pos=i;
            mn=reb[i].b;
        }
        used[i]=true;
        v[reb[i].x].push_back(make_pair(reb[i].y,reb[i].a));
        v[reb[i].y].push_back(make_pair(reb[i].x,reb[i].a));
        p[x]=y;
    }

}
void dfs(int x,int y,long long z){
    pred[x][0]=y;
    dp[x][0]=z;
    tin[x]=++timer;
    for (int i=1;i<=20;++i) {
        pred[x][i]=pred[pred[x][i-1]][i-1];
        dp[x][i]=max(dp[x][i-1],dp[pred[x][i-1]][i-1]);
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        long long len=v[x][i].second;
        if (to==y) continue;
        dfs(to,x,len);
    }
    tout[x]=++timer;
}
inline bool f(int x,int y){
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
inline int get_lca(int x,int y){
    if (f(x,y)) return x;
    else if (f(y,x)) return y;
    for (int i=20;i>0;--i)
        if (pred[x][i] && f(pred[x][i],y)==false) x=pred[x][i];
    return pred[x][0];
}
inline long long get_max(int x,int y){
    long long res=0;
    for (int i=20;i>=0;--i)
    if (pred[x][i] && f(pred[x][i],y)==false) {
        res=max(res,dp[x][i]);
        x=pred[x][i];
    }
    if (x!=y) {
        res=max(res,dp[x][0]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        reb[i].id=i;
        cin>>reb[i].a;
    }
    for (int i=1;i<=m;++i) {
        cin>>reb[i].b;
    }
    for (int i=1;i<=m;++i) {
        cin>>reb[i].x>>reb[i].y;
    }
    cin>>s;
    build_tree();
    ans=all-s/mn;
    dfs(1,0,0);
    for (int i=1;i<=m;++i)
        if (used[i]==false) {
            int x=reb[i].x;
            int y=reb[i].y;
            int z=get_lca(x,y);
            long long mx=get_max(x,z);
            mx=max(mx,get_max(y,z));
            if (all-mx+reb[i].a-s/reb[i].b<ans) {
                ans=all-mx+reb[i].a-s/reb[i].b;
                pos=i;
            }
        }
    reb[pos].a-=s/reb[pos].b;
    build_tree();
    cout<<all<<'\n';
    for (int i=1;i<=m;++i)
        if (used[i])
        cout<<reb[i].id<<" "<<reb[i].a<<'\n';
}