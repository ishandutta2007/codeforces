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
const int MAXN=3e5+10,LIM=3e5;
int n,a[MAXN],b[MAXN],c[MAXN];
int logn[MAXN];
array<int,2> f[20][MAXN];
struct ST{
    int st[20][MAXN];
    int val[MAXN];
    void build(int* a,int n){
        rep(i,1,n)val[i]=a[i];
        rep(i,1,n)st[0][i]=i;
        rep(j,1,19)rep(i,1,n)if(i+(1<<j)-1>n)break;
        else st[j][i]=(val[st[j-1][i]]<val[st[j-1][i+(1<<(j-1))]])?(st[j-1][i]):(st[j-1][i+(1<<(j-1))]);
    }
    int qry(int l,int r){
        int len=logn[r-l+1];
        return (val[st[len][l]]<val[st[len][r-(1<<len)+1]])?(st[len][l]):(st[len][r-(1<<len)+1]);
    }
}LL,RR;
int main(){
    //freopen("sn.in","r",stdin);
    //freopen("sn.out","w",stdout);
    logn[0]=-1;rep(i,1,LIM)logn[i]=logn[i>>1]+1;
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>a[i],a[i+n]=a[i+n+n]=a[i];
    if(n==1){
        cout<<"0"<<endl;
        return 0;
    }
    rep(i,1,3*n)b[i]=max(1,i-a[i]),c[i]=-min(3*n,i+a[i]);
    LL.build(b,3*n);RR.build(c,3*n);
    rep(i,1,3*n)f[0][i]={b[i],-c[i]};
    rep(j,1,19)rep(i,1,3*n){
        int lp=LL.qry(f[j-1][i][0],f[j-1][i][1]);
        int rp=RR.qry(f[j-1][i][0],f[j-1][i][1]);
        f[j][i][0]=min(f[j-1][i][0],min(f[j-1][lp][0],f[j-1][rp][0]));
        f[j][i][1]=max(f[j-1][i][1],max(f[j-1][lp][1],f[j-1][rp][1]));
    }
    rep(i,1,n){
        int res=0;
        int L=n+i,R=n+i;
        per(j,19,0){
            int lp=LL.qry(L,R),rp=RR.qry(L,R);
            int nL=min(L,min(f[j][lp][0],f[j][rp][0]));
            int nR=max(R,max(f[j][lp][1],f[j][rp][1]));
            if(nR-nL+1<n){
                res+=(1<<j);
                L=nL,R=nR;
            }
        }
        cout<<res+1<<" ";
    }
    return 0;
}