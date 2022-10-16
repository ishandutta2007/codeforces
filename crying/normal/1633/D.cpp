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
const int MAXN=1e3+10,MAXM=2e4+10;
int t,n,k,f[MAXN],b[MAXN],c[MAXN];
int dp[MAXM];
void solve(){
    cin>>n>>k;
    rep(i,1,n)cin>>b[i];
    rep(i,1,n)cin>>c[i];
    if(k>=n*20){
        int ret=0;rep(i,1,n)ret+=c[i];
        printf("%d\n",ret);
        return;
    }
    rep(i,0,k)dp[i]=0;
    rep(i,1,n){
        per(j,k,f[b[i]]){
            dp[j]=max(dp[j],dp[j-f[b[i]]]+c[i]);
        }
    }
    printf("%d\n",dp[k]);
    return;
}
int main(){
    f[1]=0;
    rep(i,2,1000)f[i]=1e9;
    rep(i,1,999){
        rep(x,1,i){
            if(i+i/x<=1000){
                f[i+i/x]=min(f[i+i/x],f[i]+1);
            }
        }
    }
    cin>>t;
    while(t--)solve();
    return 0;
}