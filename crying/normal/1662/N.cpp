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
const int MAXN=1550;
int n,a[MAXN][MAXN];
int r[MAXN][MAXN],c[MAXN][MAXN];
int t[MAXN*MAXN];
void upd(int x,int val){
    for(;x<=n*n;x+=lowbit(x))t[x]+=val;
}
int qry(int x,int s=0){
    for(;x;x-=lowbit(x))s+=t[x];
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>a[i][j];
    rep(i,1,n){
        rep(j,1,n)upd(a[i][j],1);
        rep(j,1,n)r[i][j]=qry(a[i][j])-1;
        rep(j,1,n)upd(a[i][j],-1);  
    }
    rep(i,1,n){
        rep(j,1,n)upd(a[j][i],1);
        rep(j,1,n)c[j][i]=qry(a[j][i])-1;
        rep(j,1,n)upd(a[j][i],-1);
    }
    ll ans=0;
    rep(i,1,n)rep(j,1,n)ans+=1ll*r[i][j]*(n-1-c[i][j])+1ll*c[i][j]*(n-1-r[i][j]);
    cout<<ans/2;
    return 0;
}