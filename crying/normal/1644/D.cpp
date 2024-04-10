#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=998244353;
int T,n,m,q,k,x[MAXN],y[MAXN];
int tagr[MAXN],tagc[MAXN],rc,cc;
ll ret;
void solve(){
    cin>>n>>m>>k>>q;
    ret=1;
    rep(i,1,q)cin>>x[i]>>y[i];
    rep(i,1,n)tagr[i]=0;
    rep(i,1,m)tagc[i]=0;
    rc=cc=0;
    per(i,q,1){
        int flag=0;
        int r=x[i],c=y[i];
        if(!tagr[r] && cc!=m)flag=1;
        if(!tagc[c] && rc!=n)flag=1;
        if(!tagr[r])rc++;
        if(!tagc[c])cc++;
        tagr[r]++;
        tagc[c]++;
        if(flag)ret=ret*k%mod;
    }
    cout<<ret<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}