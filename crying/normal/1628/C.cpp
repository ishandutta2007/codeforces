#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e3+10;
int T,n,a[MAXN][MAXN];
int b[MAXN][MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>a[i][j];
    rep(i,1,n)b[1][i]=114514;
    rep(i,2,n){
        rep(j,1,n){
            b[i][j]=a[i-1][j]^b[i-1][j-1]^b[i-1][j+1]^b[i-2][j];     
        }
    }
    int ans=0;
    rep(i,1,n)rep(j,1,n)ans^=b[i][j];
    printf("%d\n",ans);
    rep(i,1,n)rep(j,1,n)b[i][j]=0;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }


    return 0;
}