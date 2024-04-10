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
const int MAXN=1010;
int T,n,p[MAXN],vis[MAXN],ret[MAXN];
void solve(){
    cin>>n;memset(vis,0,sizeof vis);
    rep(i,1,n)cin>>p[i];
    if(n==1){
        puts("-1");return;
    }
    rep(i,1,n){
        int k=0;
        rep(j,1,n)if(!vis[j] && j!=p[i]){k=j;break;}
        if(i==n-1 && k!=p[n] && !vis[p[n]]){
            k=p[n];
        }
        ret[i]=k;vis[k]=1;
    }
    rep(i,1,n)cout<<ret[i]<<' ';cout<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}