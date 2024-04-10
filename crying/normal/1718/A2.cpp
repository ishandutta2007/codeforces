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
const int MAXN=1e5+10,INF=1e9;
int T,n,a[MAXN],b[MAXN];
int f[MAXN];
map<int,int>g;
void solve(){
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        b[i]=a[i]^b[i-1];
        f[i]=0;
    }

    g.clear();g[0]=0;
    rep(i,1,n){
        f[i]=f[i-1];
        if(g.find(b[i])!=g.end())f[i]=max(f[i],g[b[i]]+1);
        g[b[i]]=max(g[b[i]],f[i]);
    }

    cout<<n-f[n]<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}