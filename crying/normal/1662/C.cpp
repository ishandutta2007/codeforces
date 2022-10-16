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
const int MAXN=100,mod=998244353;
int n,m,k;
struct Matrix1{
    int val[MAXN][MAXN];
    void clr(){rep(i,0,n-1)rep(j,0,n-1)val[i][j]=0;}
    void operator=(const Matrix1 m2){rep(i,0,n-1)rep(j,0,n-1)val[i][j]=m2.val[i][j];}
    Matrix1 operator+(const Matrix1 m2)const{
        Matrix1 ret;ret.clr();
        rep(i,0,n-1)rep(j,0,n-1)ret.val[i][j]=(val[i][j]+m2.val[i][j])%mod;
        return ret;
    }
    Matrix1 operator-(const Matrix1 m2)const{
        Matrix1 ret;ret.clr();
        rep(i,0,n-1)rep(j,0,n-1)ret.val[i][j]=(val[i][j]-m2.val[i][j]+mod)%mod;
        return ret;
    }
    Matrix1 operator*(const Matrix1 m2)const{
        Matrix1 ret;ret.clr();
        rep(i,0,n-1)rep(j,0,n-1)rep(k,0,n-1)ret.val[i][j]=(ret.val[i][j]+1ll*val[i][k]*m2.val[k][j])%mod;
        return ret;
    }
};
struct Matrix2{
    Matrix1 val[2][2];
    void clr(){rep(i,0,1)rep(j,0,1)val[i][j].clr();}
    void operator=(const Matrix2 m2){rep(i,0,1)rep(j,0,1)val[i][j]=m2.val[i][j];}
    Matrix2 operator+(const Matrix2 m2)const{
        Matrix2 ret;ret.clr();
        rep(i,0,1)rep(j,0,1)ret.val[i][j]=val[i][j]+m2.val[i][j];
        return ret;
    }
    Matrix2 operator-(const Matrix2 m2)const{
        Matrix2 ret;ret.clr();
        rep(i,0,1)rep(j,0,1)ret.val[i][j]=val[i][j]-m2.val[i][j];
        return ret;
    }
    Matrix2 operator*(const Matrix2 m2)const{
        Matrix2 ret;ret.clr();
        rep(i,0,1)rep(j,0,1)rep(k,0,1)ret.val[i][j]=ret.val[i][j]+val[i][k]*m2.val[k][j];
        return ret;
    }
    Matrix2 mypow(int n)const{
        if(n==1)return (*this);
        Matrix2 ret;ret.clr();ret=mypow(n/2);ret=ret*ret;
        if(n&1)ret=ret*(*this);return ret;
    }
};
Matrix1 G,D,I,f1,f2;
Matrix2 f,A;
void calc(Matrix1 M){
    ll ret=0;
    rep(i,0,n-1)ret=(ret+M.val[i][i])%mod;
    cout<<ret<<endl;exit(0);
}
int main(){
    cin>>n>>m>>k;
    rep(i,0,n-1)I.val[i][i]=1;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        u--;v--;
        G.val[u][v]=G.val[v][u]=1;
        D.val[u][u]=(D.val[u][u]+1)%mod;
        D.val[v][v]=(D.val[v][v]+1)%mod;
    }
    f1=G;f2=f1*G-D;
    if(k==1)calc(f1);
    if(k==2)calc(f2);
    f.val[0][0]=f1;f.val[0][1]=f2;
    A.val[0][1]=I-D;A.val[1][0]=I;A.val[1][1]=G;
    f=f*A.mypow(k-2);
    calc(f.val[0][1]);
    return 0;
}