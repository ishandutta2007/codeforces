#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
struct matrix {
    long long a[2][2];
};
int n,m,x,y,z,sz;
matrix q[500005],tree[500005];
matrix def,def2,zero;
inline matrix mult(matrix a,matrix b){
    matrix res;
    for (int i=0;i<2;++i)
    for (int j=0;j<2;++j) {
        res.a[i][j]=0;
        for (int k=0;k<2;++k)
            res.a[i][j]=(res.a[i][j]+(a.a[i][k]*b.a[k][j])%md)%md;
    }
    return res;
}
inline matrix pl(matrix a,matrix b){
    for (int i=0;i<2;++i)
        for (int j=0;j<2;++j)
        a.a[i][j]=(a.a[i][j]+b.a[i][j])%md;
        return a;
}
inline void push(int x){
    if (q[x].a[0][0]==def.a[0][0] && q[x].a[0][1]==def.a[0][0] && q[x].a[1][0]==def.a[1][0] && q[x].a[1][1]==def.a[1][1]) return;
    q[x+x]=mult(q[x+x],q[x]);
    q[x+x+1]=mult(q[x+x+1],q[x]);
    tree[x+x]=mult(tree[x+x],q[x]);
    tree[x+x+1]=mult(tree[x+x+1],q[x]);
    q[x]=def;
}
void update(int l,int r,int ll,int rr,int x,matrix z){
    //push(x);
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        tree[x]=mult(tree[x],z);
        q[x]=mult(q[x],z);
        //push(x);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x,z);
    update(mid+1,r,ll,rr,x+x+1,z);
    tree[x]=mult(pl(tree[x+x],tree[x+x+1]),q[x]);
}
matrix get(int l,int r,int ll,int rr,int x){
    //push(x);
    if (l>r || ll>r || l>rr) return zero;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    return mult(pl(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1)),q[x]);
}
matrix p(matrix x,int y){
    if (y==1) return x;
    if (y&1) return mult(x,p(x,y-1));
    matrix yy=p(x,y>>1);
    return mult(yy,yy);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    def.a[0][0]=1;
    def.a[1][1]=1;
    def.a[0][1]=0;
    def.a[1][0]=0;
    def2.a[0][0]=0;
    def2.a[1][1]=1;
    def2.a[0][1]=1;
    def2.a[1][0]=1;
    zero.a[0][0]=0;
    zero.a[0][1]=0;
    zero.a[1][0]=0;
    zero.a[1][1]=0;
    sz=1;
    while (sz<n) sz<<=1;
    for (int i=1;i<sz;++i)
        q[i]=def;
    for (int i=1;i<=n;++i) {
        matrix xx=def2;
        cin>>z;
        xx=p(xx,z);
        tree[sz+i-1]=xx;
    }
    for (int i=sz-1;i>0;--i)
        tree[i]=pl(tree[i+i],tree[i+i+1]);
    for (int i=1;i<=m;++i) {
        cin>>x;
        if (x==2) {
            cin>>x>>y;
            matrix zz=get(1,sz,x,y,1);
            cout<<zz.a[0][1]<<'\n';
        } else {
            cin>>x>>y>>z;
            matrix zz=def2;
            zz=p(zz,z);
            update(1,sz,x,y,1,zz);
        }
    }

}