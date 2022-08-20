#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

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
const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

template<int SZ> struct mat {
    array<array<ll,SZ>,SZ> d;
    
    mat() {
        F0R(i,SZ) F0R(j,SZ) d[i][j] = 0;
    }
    
    mat operator+(const mat& m) {
        mat<SZ> a;
        F0R(i,SZ) F0R(j,SZ) a.d[i][j] = (d[i][j]+m.d[i][j]) % MOD;
        return a;
    }
    
    mat operator*(const mat& m) {
        mat<SZ> a;
        F0R(i,SZ) F0R(j,SZ) F0R(k,SZ) 
            a.d[i][k] = (a.d[i][k]+d[i][j]*m.d[j][k]) % MOD;
        return a;
    }
    
    mat operator^(ll p) {
        mat<SZ> a, b(*this); 
        F0R(i,SZ) a.d[i][i] = 1;
        
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p /= 2;
        }
        
        return a;
    }
    
    void print() {
        F0R(i,SZ) {
            F0R(j,SZ) cout << d[i][j] << " ";
            cout << "\n";
        }
        cout << "------------\n";
    }
};

mat<101> f[101];
int n,x;
string s, ret;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> s;
    ret = s.substr(1,sz(s)-1);
    while (ret != s.substr(0,sz(ret))) ret = ret.substr(1,sz(ret)-1);
    
    F0R(i,n) {
        f[0].d[i][i] = f[1].d[i][i] = 1;
        if (s[i] == '0') {
            f[0].d[i][i+1] ++;
            if (i == n-1) f[0].d[i][sz(ret)] ++;
            
            string t = s.substr(0,i)+'1';
            while (t != s.substr(0,sz(t))) t = t.substr(1,sz(t)-1);
            f[1].d[i][sz(t)] ++;
        } else {
            f[1].d[i][i+1] ++;
            if (i == n-1) f[1].d[i][sz(ret)] ++;
            
            string t = s.substr(0,i)+'0';
            while (t != s.substr(0,sz(t))) t = t.substr(1,sz(t)-1);
            f[0].d[i][sz(t)] ++;
        }
    }
    f[0].d[n][n] = f[1].d[n][n] = 2;
    FOR(i,2,101) f[i] = f[i-1]*f[i-2];
    cout << f[x].d[0][n];
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)