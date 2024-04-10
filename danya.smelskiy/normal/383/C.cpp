#include <bits/stdc++.h>
using namespace std;

vector<int> q;
int timer;
int tin[200005];
int tout[200005];
vector<int> v[200005];
long long tree1[1000000];
long long tree2[1000000];
long long res;
long long a[200005];
int depth[200005];
int sz;
int n,m,x,y;
void dfs(int x,int p,int d){
    q.push_back(x);
    depth[x]=d;
    tin[x]=++timer;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to!=p) dfs(to,x,d+1);
    }
    tout[x]=timer;
}
void get1(int l,int r,int y,int x){
    res+=tree1[x];
    if (l==r) return;
    int mid=(l+r)/2;
    if (y>mid) get1(mid+1,r,y,x+x+1);
    else get1(l,mid,y,x+x);
}
void get2(int l,int r,int y,int x){
    res+=tree2[x];
    if (l==r) return;
    int mid=(l+r)/2;
    if (y>mid) get2(mid+1,r,y,x+x+1);
    else get2(l,mid,y,x+x);
}
void up1(int l,int r,int ll,int rr,int x,int y){
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {tree1[x]+=y; return; }
    int mid=(l+r)/2;
    up1(l,mid,ll,rr,x+x,y);
    up1(mid+1,r,ll,rr,x+x+1,y);
}
void up2(int l,int r,int ll,int rr,int x,int y){
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr){ tree2[x]+=y; return ;}
    int mid=(l+r)/2;
    up2(l,mid,ll,rr,x+x,y);
    up2(mid+1,r,ll,rr,x+x+1,y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1,0);
    sz=1;
    while (sz<q.size()) sz+=sz;
    for (int i=1;i<=m;++i) {
        cin>>x;
        if (x==2) {
            cin>>y;
            res=0;
            if (depth[y]%2==1) get2(1,sz,tin[y],1);
            else get1(1,sz,tin[y],1);
            cout<<a[y]+res<<'\n';
        } else {
            cin>>x>>y;
            if (depth[x]%2==1) {
                up2(1,sz,tin[x],tout[x],1,y);
                up1(1,sz,tin[x],tout[x],1,-y);
            } else {
                up2(1,sz,tin[x],tout[x],1,-y);
                up1(1,sz,tin[x],tout[x],1,y);
            }
        }
    }
}