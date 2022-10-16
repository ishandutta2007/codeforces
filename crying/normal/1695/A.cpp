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
const int MAXN=50,INF=2e9;
int T,n,m,a[MAXN][MAXN],maxn;
void solve(){
    cin>>n>>m;maxn=-INF;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j],maxn=max(maxn,a[i][j]);
    rep(i,1,n)rep(j,1,m)if(a[i][j]==maxn){
        int w=max(j,m-j+1),h=max(i,n-i+1);
        cout<<w*h<<endl;return;
    }
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }


    return 0;
}