#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=19;
lli val[MAXN];
lli rule[MAXN][MAXN];
lli dp[524289][MAXN];
lli MINV=-1e14;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    sc(n,m,k);
    rep(i,0,n){
        sc(val[i]);
    }
    int a,b;
    lli c;
    rep(i,0,k){
        sc(a,b,c);
        a-=1,b-=1;
        rule[a][b]=c;
    }
    lli ans=0;
    rep(i,1,(1<<n)){
        rep(j,0,n){
            dp[i][j]=MINV;
            if(i&(1<<j)&&__builtin_popcount(i)>1)rep(k,0,n){
                dp[i][j]=max(dp[i][j],dp[i-(1<<j)][k]+val[j]+rule[k][j]);
            }
        }
        if(__builtin_popcount(i)==1){
            rep(j,0,n){
                if(i&(1<<j))dp[i][j]=val[j];
            }
        }
        if(__builtin_popcount(i)==m){
            rep(j,0,n)ans=max(ans,dp[i][j]);
        }
    }
    prl(ans);
    return 0;
}