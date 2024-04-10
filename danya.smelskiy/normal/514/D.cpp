#include <bits/stdc++.h>
using namespace std;



int n,m,k,sz;
int tree[6][600001];

int get(int l,int r,int ll,int rr,int x,int y){
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) { return tree[y][x];}
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,x+x,y),get(mid+1,r,ll,rr,x+x+1,y));
}
inline bool chek(int mid){
    if (mid==0) return 0;
    for (int i=mid;i<=n;++i) {
        int kol=0;
        for (int j=1;j<=m;++j)
            kol+=get(1,sz,i-mid+1,i,1,j);
        if (kol<=k) return true;
    }
    return false;
}
inline void f(int mid ) {
    if (mid==0) {
        for (int i=1;i<=m;++i)
            cout<<"0 ";
        exit(0);
    }
    for (int i=mid;i<=n;++i) {
        int res=0;
        for (int j=1;j<=m;++j)
            res+=get(1,sz,i-mid+1,i,1,j);
        if (res<=k) {
            for (int j=1;j<=m;++j)
                cout<<get(1,sz,i-mid+1,i,1,j)<<" ";
            exit(0);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin>>tree[j][sz+i-1];
        }
    }
    for (int i=1;i<=m;++i) {
        for (int j=sz-1;j>0;--j)
            tree[i][j]=max(tree[i][j+j],tree[i][j+j+1]);
    }
    int l=0;
    int r=n;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (chek(mid)) l=mid;
        else r=mid;
    }
    if (chek(r)) f(r);
    else f(l);
}