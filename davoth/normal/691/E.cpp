#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e7+10,LN=29;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
template<class T , ll SZ>
struct Mat {
    ll n, m;
    T mat[SZ][SZ];

    Mat(ll N , ll M) {
        n = N;
        m = M;
        Fill(0);
    }

    template <class U> Mat(const initializer_list<initializer_list<U>>& vec) {
        auto u = vec.begin();
        n = vec.size() ; m = (*u).size();
        for (ll i = 0; i < n; i++, u++) {
            auto v = u->begin();
            for (ll j = 0; j < m; j++, v++) {
                mat[i][j] = (*v);
            }
        }
    }

    void Fill(T x) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                mat[i][j] = x;
            }
        }
    }

    void zero(){
        Fill(0);
        for(ll i = 0 ; i < n ; i++) mat[i][i] = 1;
    }

    friend Mat operator+(const Mat &x ,const Mat &y) {
        assert(x.n == y.n && x.m == y.m);
        Mat ans = Mat(x.n , x.m);
        for (ll i = 0; i < x.n; i++) {
            for (ll j = 0; j < x.m; j++) {
                ans.mat[i][j] = (x.mat[i][j] + y.mat[i][j]) % MOD;
            }
        }
        return ans;
    }

    friend Mat operator*(const Mat &x ,const Mat &y) {
        assert(x.m == y.n);
        Mat ans = Mat(x.n , y.m);
        for (ll i = 0; i < x.n; i++) {
            for (ll j = 0; j < y.m; j++) {
                for (ll k = 0; k < x.m; k++) {
                    ans.mat[i][j] += (x.mat[i][k] * y.mat[k][j]);
                    ans.mat[i][j] %= MOD;
                }
            }
        }
        return ans;
    }

    friend Mat operator^(Mat t , ll x) {
        assert(t.n == t.m);
        Mat ans = Mat(t.n , t.m);
        for(ll i = 0 ; i < t.n ; i++)   ans.mat[i][i] = 1;
        while (x != 0) {
            if (x & 1) ans = ans * t;
            x >>= 1;
            t = t * t;
        }
        return ans;
    }

    /*friend Mat operator*(const Mat &x ,const ll y) {
        Mat ans = Mat(x.n , x.m);
        for (ll i = 0; i < x.n; i++) {
            for (ll j = 0; j < x.m; j++) {
                ans.mat[i][j] = (x.mat[i][j] * y) % MOD;
            }
        }
        return ans;
    }*/
};
ll n, k, a[100], ans;
bool f[100][100];
Mat<ll,100> A(100,1), C(100,100), an(100,1);
int main() {
    fast_io;
    cin >> n >> k;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            f[i][j]=__builtin_popcountll(a[i]^a[j])%3==0;
        }
    }
    for(ll i=0; i<n; i++) A.mat[i][0]=1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(f[i][j]) C.mat[j][i]=1;
        }
    }
    an=(C^(k-1))*A;
    for(ll i=0; i<n; i++) ans+=an.mat[i][0],ans%=MOD;
    cout << ans;
    return 0;
}