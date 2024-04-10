#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
#define int ll
const int MAXN=1e5+10,INF=1e18;
struct Matrix{
    int n,m,a[2][2];
    void reset(int n,int m){this->n=n;this->m=m;rep(i,0,n-1)rep(j,0,m-1)a[i][j]=INF;}
    void operator=(const Matrix& m2){reset(m2.n,m2.m);rep(i,0,n-1)rep(j,0,m-1)a[i][j]=m2.a[i][j];}
    Matrix operator*(const Matrix& m2)const{
        Matrix ret;ret.reset(n,m2.m);
        rep(i,0,ret.n-1)rep(j,0,ret.m-1)rep(k,0,m-1){
            ret.a[i][j]=min(ret.a[i][j],a[i][k]+m2.a[k][j]);
        }
        return ret;
    }
}I,A[MAXN];
int L(int x,int y){return max(x,y);}
int D(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
int d[MAXN][4],n,val[MAXN][2][2];
struct Seg{
    Matrix val[MAXN<<2];
    void pushup(int x){
        val[x]=val[lc(x)]*val[rc(x)];
    }
    void build(int x,int l,int r){
        if(l==r){
            val[x]=A[l];return;
        }
        int mid=(l+r)>>1;
        build(lc(x),l,mid);build(rc(x),mid+1,r);
        pushup(x);
    }
    Matrix qry(int x,int l,int r,int ql,int qr){
        if(ql>qr)return I;
        if(ql<=l && qr>=r)return val[x];
        int mid=(l+r)>>1;
        Matrix ret=I;
        if(ql<=mid)ret=ret*qry(lc(x),l,mid,ql,qr);
        if(qr>mid)ret=ret*qry(rc(x),mid+1,r,ql,qr);
        return ret;
    }
}seg;
signed main(){
    ios::sync_with_stdio(false);
    I.reset(2,2);I.a[0][0]=I.a[1][1]=0;
    cin>>n;
    rep(i,1,n-1){
        cin>>d[i][0]>>d[i][1]>>d[i][2]>>d[i][3];
    }
    rep(i,1,n-1){
        int cx=d[i][0]+1,cy=d[i][1];
        val[i][0][0]=D(cx,cy,d[i+1][0],d[i+1][1])+1;
        val[i][0][1]=D(cx,cy,d[i+1][2],d[i+1][3])+1;
        cx=d[i][2],cy=d[i][3]+1;
        val[i][1][0]=D(cx,cy,d[i+1][0],d[i+1][1])+1;
        val[i][1][1]=D(cx,cy,d[i+1][2],d[i+1][3])+1;
    }
    rep(i,1,n-1){
        A[i].reset(2,2);
        rep(x,0,1)rep(y,0,1)A[i].a[x][y]=val[i][x][y];
    }
    seg.build(1,1,n-1);
    int q,x1,y1,x2,y2;
    cin>>q;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        if(L(x1,y1)>L(x2,y2))swap(x1,x2),swap(y1,y2);
        if(L(x1,y1)==L(x2,y2)){
            cout<<D(x1,y1,x2,y2)<<'\n';continue;
        }
        int l1=L(x1,y1),l2=L(x2,y2);
        Matrix ret;ret.reset(1,2);
        ret.a[0][0]=D(x1,y1,d[l1][0],d[l1][1]);
        ret.a[0][1]=D(x1,y1,d[l1][2],d[l1][3]);
        ret=ret*seg.qry(1,1,n-1,l1,l2-2);
        int ans=INF;
        int cx=d[l2-1][0]+1,cy=d[l2-1][1];
        ans=min(ans,1+ret.a[0][0]+D(cx,cy,x2,y2));
        cx=d[l2-1][2],cy=d[l2-1][3]+1;
        ans=min(ans,1+ret.a[0][1]+D(cx,cy,x2,y2));
        cout<<ans<<'\n';
    }
    return 0;
}