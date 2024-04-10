#include <bits/stdc++.h>
using namespace std;
int all;
int lz[4000001];
int rz[4000001];
int root[100005];
int tree[4000001];
int n,m,x,y;
int sz;
int a[100001];
int kol[100001];
vector<int> v[100001];

inline int vcopy(int x){
    ++all;
    lz[all]=lz[x];
    rz[all]=rz[x];
    tree[all]=tree[x];
    return all;
}
inline void update(int l,int r,int x,int y,int z){
    if (l==r) {
        tree[x]=z;
        return;
    }
    int mid=(l+r)/2;
    if (y<=mid) {
        lz[x]=vcopy(lz[x]);
        update(l,mid,lz[x],y,z);
    } else {
        rz[x]=vcopy(rz[x]);
        update(mid+1,r,rz[x],y,z);
    }
    tree[x]=tree[lz[x]]+tree[rz[x]];
}
inline int get(int l,int r,int ll,int rr,int x){
    if (l>r || l>rr || r<ll || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)/2;
    return get(l,mid,ll,rr,lz[x])+get(mid+1,r,ll,rr,rz[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=sz;++i){
        lz[i]=i+i;
        rz[i]=i+i;
    }
    root[0]=1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        root[i]=vcopy(root[i-1]);
        ++kol[a[i]];
        v[a[i]].push_back(i);
        update(1,sz,root[i],i,1);
        if (kol[a[i]]==m+1) {
            --kol[a[i]];
            update(1,sz,root[i],v[a[i]][v[a[i]].size()-m-1],0);
        }
    }
    int k;
    cin>>k;
    int last=0;
    for (int i=1;i<=k;++i) {
        cin>>x>>y;
        x=(x+last)%n+1;
        y=(y+last)%n+1;
        if (x>y) swap(x,y);
        last=get(1,sz,x,y,root[y]);
        cout<<last<<'\n';
    }
}