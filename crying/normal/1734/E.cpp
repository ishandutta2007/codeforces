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
const int MAXN=510;
int n,b[MAXN];
int a[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,0,n-1)cin>>b[i];
    rep(i,0,n-1)rep(j,0,n-1)a[i][j]=i*j%n;

    rep(i,0,n-1){
        int diff=(b[i]-a[i][i]+n)%n;
        rep(j,0,n-1)a[i][j]=(a[i][j]+diff)%n;
    }

    rep(i,0,n-1){
        rep(j,0,n-1)cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}