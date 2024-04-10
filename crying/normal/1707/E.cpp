#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Max(a,b) (a>b)?(a):(b)
#define Min(a,b) (a<b)?(a):(b)
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
const int MAXN=1e5+10,LIM=1e5,INF=1e9;
int n,q,a[MAXN];
int logn[MAXN];
array<int,2> Merge(const array<int,2>&a1,const array<int,2>& a2){
    if(a1[0]==-1 || a2[0]==-1)return {-1,-1};
    return {Min(a1[0],a2[0]),Max(a1[1],a2[1])};
}
struct ST{
    int minn[18][MAXN];
    void build(int* a,int flag){
        rep(i,1,n)minn[0][i]=flag*a[i];
        rep(i,1,17){
            rep(j,1,n)if(j+(1<<i)-1>n)break;else{
                minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int qry(int l,int r,int flag=1){
        int len=logn[r-l+1];
        return min(minn[len][l],minn[len][r-(1<<len)+1])*flag;
    }
}minst,maxst,Lst[35],Rst[35];
array<int,2>qry(int L,int R){
    return {minst.qry(L,R),-maxst.qry(L,R)};
}

int L[35][MAXN],R[35][MAXN];

int main(){
    logn[0]=-1;rep(i,1,LIM)logn[i]=logn[i>>1]+1;
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n)cin>>a[i];

    if(n==1){
        rep(i,1,q){
            ll l,r;cin>>l>>r;
            cout<<"0\n";
        }
        exit(0);
    }
    minst.build(a,1);maxst.build(a,-1);
    rep(i,1,n-1)L[0][i]=min(a[i],a[i+1]),R[0][i]=max(a[i],a[i+1]);
    Lst[0].build(L[0],1);Rst[0].build(R[0],-1);
    rep(j,1,34){
        rep(i,1,n-1){
            int l=L[j-1][i],r=R[j-1][i];
            if(l==-INF || l==r)L[j][i]=-INF,R[j][i]=INF;
            else L[j][i]=Lst[j-1].qry(l,r-1),R[j][i]=Rst[j-1].qry(l,r-1,-1);
        }
        Lst[j].build(L[j],1);
        Rst[j].build(R[j],-1);
    }

    rep(i,1,q){
        int l,r;cin>>l>>r;
        array<int,2>now={l,r};
        if(l==r){
            cout<<"-1\n";
            continue;
        }
        if(l==1 && r==n){
            cout<<"0\n";
            continue;
        }
        ll res=0;
        per(j,34,0){
            array<int,2>to={Lst[j].qry(now[0],now[1]-1),Rst[j].qry(now[0],now[1]-1,-1)};
            if(to[0]==1 && to[1]==n)continue;
            if(to[0]==to[1])continue;
            if(to[0]==-INF)continue;
            res+=(1LL<<j);
            now=to;
        }
        now={Lst[0].qry(now[0],now[1]-1),Rst[0].qry(now[0],now[1]-1,-1)};
        if(now[0]==1 && now[1]==n){
            cout<<res+1<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    
    return 0;
}