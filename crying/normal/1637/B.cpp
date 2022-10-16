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
const int MAXN=110,INF=1e9;
int T,n,a[MAXN],f[MAXN][MAXN][2],g[MAXN][MAXN];
map<int,int>b;
void solve(){
    cin>>n;rep(i,1,n)cin>>a[i];
    rep(i,0,n)rep(j,0,n)f[i][j][0]=-INF;
    rep(i,1,n){
        b.clear();int cur=0;
        rep(j,i,n){
            b[a[j]]++;
            while(b[cur])cur++;
            g[i][j]=cur;
        }
        f[i][i][0]=g[i][i]+1;
        f[i][i][1]=1;
    }
    rep(len,2,n)rep(i,1,n){
        int j=(i+len)-1;if(j>n)break;
        f[i][j][0]=g[i][j]+1;f[i][j][1]=1;
        rep(k,i,j-1){
            if(f[i][k][0]+f[k+1][j][0]>f[i][j][0]){
                f[i][j][0]=f[i][k][0]+f[k+1][j][0];
                f[i][j][1]=f[i][k][1]+f[k+1][j][1];
            }
        }
    }
    ll ans=0;
    rep(i,1,n)rep(j,i,n)ans+=f[i][j][0];
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}