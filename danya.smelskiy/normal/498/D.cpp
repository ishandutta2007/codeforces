#include <bits/stdc++.h>
using namespace std;


int n,sz;
int t[400000][60];
int a[100005];
//
void build(int l,int r,int x){
    if (l==r || l>n) return;
    int mid=(l+r)>>1;
    build(l,mid,x+x);
    build(mid+1,r,x+x+1);
    for (int i=0;i<60;++i) {
        int res1=t[x+x][i];
        int res2=(i+res1)%60;
        t[x][i]=(res1+t[x+x+1][res2]);
    }
}
void update(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return;
    if (l==r) return;
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    for (int i=0;i<60;++i) {
        int res1=t[x+x][i];
        int res2=(i+res1)%60;
        t[x][i]=(res1+t[x+x+1][res2]);
    }
}
int get(int l,int r,int ll,int rr,int x,int y){
    if (l>=ll && r<=rr) return y+t[x][y%60];
    int mid=(l+r)>>1;
    if (rr<=mid) return get(l,mid,ll,rr,x+x,y);
    else if (ll>mid) return get(mid+1,r,ll,rr,x+x+1,y);
    int res=get(l,mid,ll,rr,x+x,y);
    return get(mid+1,r,ll,rr,x+x+1,res);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        for (int j=0;j<60;++j) if (j%a[i]==0) {
            t[sz+i-1][j]=2;
        } else t[sz+i-1][j]=1;
    }
    int m;
    build(1,sz,1);
    cin>>m;
    for (int i=1;i<=m;++i) {
        char c; int x,y;
        cin>>c>>x>>y;
        if (c=='A') {
            --y;
            cout<<get(1,sz,x,y,1,0)<<'\n';
        } else {
            a[x]=y;
            for (int j=0;j<60;++j) if (j%a[x]==0) {
                t[sz+x-1][j]=2;
            } else t[sz+x-1][j]=1;
            update(1,sz,x,x,1);
        }
    }
}