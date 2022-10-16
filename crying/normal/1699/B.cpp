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
const int MAXN=100;
int T,n,m;
int a[MAXN][MAXN];

void solve(){
    cin>>n>>m;
    rep(i,0,n/2-1)rep(j,0,m/2-1){
        if(odd((i+j))){
            a[i*2+1][j*2+1]=a[i*2+2][j*2+2]=1;
            a[i*2+1][j*2+2]=a[i*2+2][j*2+1]=0;
        }else{
            a[i*2+1][j*2+1]=a[i*2+2][j*2+2]=0;
            a[i*2+1][j*2+2]=a[i*2+2][j*2+1]=1;
        }
    }
    rep(i,1,n){
        rep(j,1,m)cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}