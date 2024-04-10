#include <bits/stdc++.h>
using namespace std;

int timer;
int n,m;
int t[1000000];
int tin[200005],tout[200005];
vector<int> v[200005];
int q[1000000];
int sz;
void dfs(int x){
    tin[x]=++timer;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to);
    }
    tout[x]=timer;
}
void push(int x,int l,int r){
    if (!q[x]) return;
    q[x+x]^=1;
    q[x+x+1]^=1;
    q[x]=0;
    int mid=(l+r)>>1;
    t[x+x]=mid-l+1-t[x+x];
    t[x+x+1]=r-mid-t[x+x+1];
}
void update(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x,l,r);
    if (l>r || ll>r || l>rr) return ;
    if (l>=ll && r<=rr) {
        q[x]^=1;
        t[x]=r-l+1-t[x];
        if (l!=r) push(x,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    t[x]=t[x+x]+t[x+x+1];
}
int get(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x,l,r);
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    dfs(1);
    sz=1;
    while (sz<timer) sz+=sz;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        t[sz-1+tin[i]]=x;
    }
    for (int i=sz-1;i>0;--i)
        t[i]=t[i+i]+t[i+i+1];
    cin>>m;
    for (int i=1;i<=m;++i){
        string s;
        int x;
        cin>>s>>x;
        if (s=="get") cout<<get(1,sz,tin[x],tout[x],1)<<'\n';
        else {
            update(1,sz,tin[x],tout[x],1);
        }
    }
}