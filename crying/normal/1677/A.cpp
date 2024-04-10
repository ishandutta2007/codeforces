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
const int MAXN=5010;
int T;
int n,p[MAXN],f[MAXN][MAXN];
ll ans;
ll t[MAXN];
void upd(int x,ll val){
    for(;x<=n;x+=lowbit(x))t[x]+=val;
}
ll qry(int x,ll s=0){
    for(;x;x-=lowbit(x))s+=t[x];
    return s;
}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>p[i];
    rep(i,1,n)rep(j,1,n)f[i][j]=0;
    memset(t,0,sizeof t);
    per(j,n,1){
        per(i,j,1){
            f[i][j]=f[i+1][j];
            f[i][j]+=qry(p[i]);
        }
        if(j<n)upd(p[j+1],1);
    }
    ans=0;
    rep(i,1,n)rep(j,i+1,n){
        if(p[i]<p[j])ans+=f[i+1][j-1];
    }  
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();    
    return 0;
}