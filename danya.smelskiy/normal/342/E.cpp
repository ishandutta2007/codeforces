#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
map<pair<int,int>,int> depth;
int kol[100005];
vector<int> v[100005];
bool used[100005],usedk[100005];
int pred[100005];
int ans[100005];
int qq;

void dfs1(int x,int p,int last,int d){
    depth[make_pair(last,x)]=d;
    kol[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==p || used[to]) continue;
        dfs1(to,x,last,d+1);
        kol[x]+=kol[to];
    }
}
int dfs2(int x,int y,int k){
    bool t=true;
    if (!((k-kol[x])<=k/2)) t=false;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y || used[to]) continue;
        int res=dfs2(to,x,k);
        if (res!=-1) return res;
        if (kol[to]>k/2) t=false;
    }
    if (t==false) return -1;
    else return x;
}

void build(int x,int y){
    dfs1(x,-1,y,1);
    int nw=dfs2(x,-1,kol[x]);
    pred[nw]=y;
    used[nw]=true;
    for (int i=0;i<v[nw].size();++i) {
        int to=v[nw][i];
        if (used[to]==false) build(to,nw);
    }
}
void update(int x,int y){
    if (x==0) return;
    ans[x]=min(ans[x],depth[make_pair(x,y)]);
    update(pred[x],y);
}
void get(int x,int y){
    if (x==0) return;
    qq=min(qq,ans[x]+depth[make_pair(x,y)]);
    get(pred[x],y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(1,0);
    for (int i=1;i<=n;++i)
        ans[i]=1e9;
    update(1,1);
    usedk[1]=true;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        if (x==1) {
            usedk[y]=true;
            update(y,y);
        } else {
            qq=1e9;
            get(y,y);
            cout<<qq<<'\n';
        }
    }
}