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
const int MAXN=510,INF=2e9;
int T,n,minn,c[MAXN][MAXN];
ll ret=0;
void solve(){
    cin>>n;
    ret=0;minn=INF;
    rep(i,1,2*n)rep(j,1,2*n){
        cin>>c[i][j];
        if(i>n && j>n)ret+=c[i][j];
        if(i==1 && (j==n+1 || j==2*n))minn=min(minn,c[i][j]);
        if(i==n && (j==n+1 || j==2*n))minn=min(minn,c[i][j]);
        if(j==1 && (i==n+1 || i==2*n))minn=min(minn,c[i][j]);
        if(j==n && (i==n+1 || i==2*n))minn=min(minn,c[i][j]);
    }
    printf("%lld\n",ret+minn);
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}