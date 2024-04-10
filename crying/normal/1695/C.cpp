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
int T,n,m,a[MAXN][MAXN];
array<int,2>f[MAXN][MAXN];
array<int,2>Merge(array<int,2> x,array<int,2> y){
    return {min(x[0],y[0]),max(x[1],y[1])};
}
void solve(){
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    if(even(n+m)){cout<<"NO\n";return;}
    f[1][1]={a[1][1],a[1][1]};
    rep(i,1,n)rep(j,1,m){
        if(i==1 && j==1)continue;
        if(i==1)f[i][j]=f[i][j-1];
        else if(j==1)f[i][j]=f[i-1][j];
        else f[i][j]=Merge(f[i][j-1],f[i-1][j]);        
        f[i][j][0]+=a[i][j],f[i][j][1]+=a[i][j];
    }
    if(f[n][m][0]<=0 && f[n][m][1]>=0)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}