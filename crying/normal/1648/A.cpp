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
const int MAXN=1e5+10;
vector<int>a[MAXN];
int n,m;
ll cnt[MAXN],sum[MAXN];
ll ans;
int main(){
    cin>>n>>m;
    rep(i,1,n){
        a[i].resize(m+10);
        rep(j,1,m)cin>>a[i][j];
    }
    rep(i,1,n){
        rep(j,1,m){
            ans+=cnt[a[i][j]]*i-sum[a[i][j]];
        }
        rep(j,1,m){
            cnt[a[i][j]]++;
            sum[a[i][j]]+=i;
        }
    }
    memset(cnt,0,sizeof cnt);
    memset(sum,0,sizeof sum);
    rep(j,1,m){
        rep(i,1,n){
            ans+=cnt[a[i][j]]*j-sum[a[i][j]];
        }
        rep(i,1,n){
            cnt[a[i][j]]++;
            sum[a[i][j]]+=j;
        }
    }
    cout<<ans;
    return 0;
}