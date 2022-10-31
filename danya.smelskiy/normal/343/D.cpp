#include <bits/stdc++.h>
using namespace std;

int tin[500005];
int tout[500005];
int pred[500005];
vector<int> v[500005];
int tree[2000001];
int timer;
bool q[2000001];
int n,x,y;
int sz;
void dfs(int x,int p){
    tin[x]=++timer;
    pred[x]=p;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=p) dfs(to,x);
    }
    tout[x]=timer;
}
inline void push(int x,int l,int r){
    if (q[x]==false) return;
    q[x]=false;
    q[x+x]=true;
    q[x+x+1]=true;
    int mid=(l+r)/2;
    tree[x+x]=(mid-l+1);
    tree[x+x+1]=(mid-l+1);
}
int get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0;
    if (l!=r) push(x,l,r);
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)/2;
    int res=get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
    tree[x]=tree[x+x]+tree[x+x+1];
    return res;
}
void up(int l,int r,int ll,int rr,int x,int y){
    if (l>r || l>rr || ll>r) return;
    if (l!=r) push(x,l,r);
    if (l>=ll && r<=rr) {
        if (y==0) {
            q[x]=false;
            tree[x]=0;
            return;
        }
        q[x]=true;
        tree[x]=(r-l+1);
        return;
    }
    int mid=(l+r)/2;
    up(l,mid,ll,rr,x+x,y);
    up(mid+1,r,ll,rr,x+x+1,y);
    tree[x]=tree[x+x]+tree[x+x+1];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    sz=1;
    while (sz<n) sz+=sz;
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        if (x==1) {
            int sum=get(1,sz,tin[y],tout[y],1);
            int kol=tout[y]-tin[y]+1;
            if (sum<kol && pred[y]!=-1) {
                up(1,sz,tin[pred[y]],tin[pred[y]],1,0);
            }
            up(1,sz,tin[y],tout[y],1,1);
        } else if (x==2) {
            up(1,sz,tin[y],tin[y],1,0);
        } else {
            int sum=get(1,sz,tin[y],tout[y],1);
            int kol=tout[y]-tin[y]+1;
            if (sum<kol) cout<<"0"<<'\n';
            else cout<<"1"<<'\n';
        }
    }
}