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
const int MAXN=2e5+10,INF=1e9;
struct Info{
    int dp[2][2];
    Info(){memset(dp,0,sizeof dp);}
}pre[2][2];
Info operator+(const Info& L,const Info& R){
    Info ret;
    rep(i,0,1)rep(j,0,1){
        ret.dp[i][j]=min(L.dp[0][j]+R.dp[i][0],L.dp[1][j]+R.dp[i][1]);
    }
    return ret;
}
int calc(const Info& i){return min(min(i.dp[0][0],i.dp[0][1]),min(i.dp[1][0],i.dp[1][1]));}
int L[MAXN],R[MAXN];
int n,a[MAXN];
ll ans;
struct Seg{
    Info val[MAXN<<2];
    void pushup(int x){val[x]=val[lc(x)]+val[rc(x)];}
    void build(int x,int l,int r){
        if(l==r){
            val[x]=pre[L[l]>0][R[l]>0];
            return;
        }
        int mid=(l+r)>>1;
        build(lc(x),l,mid);build(rc(x),mid+1,r);
        pushup(x);
    }
    void upd(int x,int l,int r,int pos){
        if(l==r){
            val[x]=pre[L[l]>0][R[l]>0];
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)upd(lc(x),l,mid,pos);
        else upd(rc(x),mid+1,r,pos);
        pushup(x);
    }
    Info qry(int x,int l,int r,int ql,int qr){
        if(ql>qr)return Info();
        if(qr<l || ql>r)return Info();
        if(ql<=l && qr>=r)return val[x];
        int mid=(l+r)>>1;
        Info ret=qry(lc(x),l,mid,ql,qr)+qry(rc(x),mid+1,r,ql,qr);
        return ret;
    }
}seg;
int main(){
    pre[0][0].dp[0][1]=pre[0][0].dp[1][0]=INF;
    pre[0][1].dp[1][0]=pre[0][1].dp[1][1]=1;pre[0][1].dp[0][1]=INF;
    pre[1][0].dp[0][1]=pre[1][0].dp[0][0]=1;pre[1][0].dp[1][0]=INF;
    pre[1][1].dp[0][1]=pre[1][1].dp[1][0]=pre[1][1].dp[1][1]=pre[1][1].dp[0][0]=1;
    cin>>n;
    rep(i,1,n)cin>>a[i],R[a[i]+1]++;
    L[1]=R[1]=1;
    seg.build(1,1,n+1);
    rep(i,1,n){
        Info cost=seg.qry(1,1,n+1,1,a[i]);
        ans+=calc(cost);
        if(a[i])L[a[i]+1]++,R[a[i]+1]--,seg.upd(1,1,n+1,a[i]+1);
    }
    cout<<ans;
    return 0;
}