#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=705;
//i_am_noob
int n,a[maxn];
bool good[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
vector<bool> vec[maxn][maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) rep1(j,n) good[i][j]=__gcd(a[i],a[j])!=1;
    rep(n) rep2(j,i,n) vec[i][j].resize(j-i+1);
    rep(n) vec[i][i][0]=1;
    rep(n){
        if(i>0) l[i][i]=good[i-1][i];
        if(i<n-1) r[i][i]=good[i][i+1];
    }
    rep2(j,1,n) rep(n-j){
        rep1(k,j+1){
            vec[i][i+j][k]=1;
            if(k>0) vec[i][i+j][k]=vec[i][i+j][k]&&r[i][i+k-1];
            if(k<j) vec[i][i+j][k]=vec[i][i+j][k]&&l[i+k+1][i+j];
        }
        l[i][i+j]=r[i][i+j]=0;
        if(i>0) rep2(k,i,i+j+1) l[i][i+j]=l[i][i+j]||(good[i-1][k]&&vec[i][i+j][k-i]);
        if(i+j<n-1) rep2(k,i,i+j+1) r[i][i+j]=r[i][i+j]||(good[k][i+j+1]&&vec[i][i+j][k-i]);
    }
    rep(n) if(vec[0][n-1][i]){
        print1("Yes");
        return 0;
    }
    print1("No");
    return 0;
}