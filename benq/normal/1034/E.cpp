#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n;
vl A,B;
int pc[1<<21];
ll t;

void AD(ll& a, ll b) {
    a = a^b^((a&b&t)<<1);
}

void SUB(ll& a, ll b) {
    AD(a,b^((b&t)<<1));
}

void MUL(ll& a, ll b) {
    ll sum = 0;
    F0R(i,n+1) F0R(j,(b>>(2*i))&3) AD(sum,(a<<(2*i))&((1LL<<(2*(n+1)))-1));
    a = sum;
}

void prin(vl x) {
    for (auto a: x) cout << a << " ";
    cout << "\n\n";
}

void input() {
    io();
    FOR(i,1,1<<21) pc[i] = pc[i^(i&-i)]+1;
    cin >> n;
    F0R(i,n+1) t ^= 1LL<<(2*i);
    // cout << t << "\n";
    /*F0R(i,4) F0R(j,4) {
        ll x = 4*i, y = 4*j; AD(x,y);
        cout << 4*i << " " << 4*j << " " << x << "\n";
    }*/
    string a; cin >> a;
    A.resize(1<<n); 
    F0R(i,1<<n) A[i] = (ll)(a[i]-'0')<<(2*pc[i]);
    string b; cin >> b;
    B.resize(1<<n); 
    F0R(i,1<<n) B[i] = (ll)(b[i]-'0')<<(2*pc[i]);
}

vl sos (vl dp, int x = 0) {
    int SZ = 31-__builtin_clz(sz(dp)); // sz(dp) = 1<<SZ
    F0R(i,SZ) F0R(j,1<<SZ) if (!(j&(1<<i))) {
        if (x == 0) AD(dp[j^(1<<i)],dp[j]);
        else SUB(dp[j^(1<<i)],dp[j]);
    }
    return dp;
}

int main() {
    input();
    A = sos(A); B = sos(B);
    //prin(A);
    F0R(i,1<<n) MUL(A[i],B[i]);
    //prin(A);
    A = sos(A,1);
    F0R(i,1<<n) cout << ((A[i]>>(2*pc[i]))&3);
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/