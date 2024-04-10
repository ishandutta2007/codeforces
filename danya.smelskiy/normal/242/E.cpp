#include <bits/stdc++.h>
using namespace std;

int n;
int sz;
int m;
int x,y,z;
int tree[21][500005];
int q[21][500005];
inline void push(int x,int y){
    if (q[y][x]==0) return;
    q[y][x]=0;
    q[y][x+x]^=1;
    q[y][x+x+1]^=1;
}
int get(int l,int r,int ll,int rr,int x,int y){
    if (q[y][x]) {
        tree[y][x]=(r-l+1)-tree[y][x];
        push(x,y);
    }
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return tree[y][x];
    int mid=(l+r)>>1;
    long long z=get(l,mid,ll,rr,x+x,y)+get(mid+1,r,ll,rr,x+x+1,y);
    tree[y][x]=tree[y][x+x]+tree[y][x+x+1];
    return z;
}
void update(int l,int r,int ll,int rr,int x,int y){
    if (q[y][x]) {
        tree[y][x]=(r-l+1)-tree[y][x];
        push(x,y);
    }
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        q[y][x]=1;
        tree[y][x]=(r-l+1)-tree[y][x];
        push(x,y);
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,ll,rr,x+x,y);
    update(mid+1,r,ll,rr,x+x+1,y);
    tree[y][x]=tree[y][x+x]+tree[y][x+x+1];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=1e8;++i){}
    cin>>n;
    sz=1;
    while (sz<n) sz*=2;
    for (int i=1;i<=n;++i){
        cin>>x;
        for (int j=0;j<=20;++j) if (x&(1<<j)){
            tree[j][sz+i-1]++;
        }
    }
    for (int i=20;i>=0;--i){
        for (int j=sz-1;j>0;--j)
            tree[i][j]=tree[i][j+j]+tree[i][j+j+1];
    }
    cin>>m;
    for (int k=1;k<=m;++k){
        cin>>x;
        if (x==1) {
            cin>>x>>y;
            long long last=1;
            long long ans=0;
            for (int i=0;i<=20;++i){
                long long z=get(1,sz,x,y,1,i);
                ans+=z*last;
                last*=2;
            }
            cout<<ans<<'\n';
        } else {
            cin>>x>>y>>z;
            for (int j=0;j<=20;++j)
            if (z&(1<<j)) {
                update(1,sz,x,y,1,j);
            }
        }
    }
}