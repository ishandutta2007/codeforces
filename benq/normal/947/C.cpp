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

template<int MX> struct tri {
    int nex = 0, ans = 0;
    int trie[MX][2], sz[MX]; // easily changed to character
    
    tri() {
        memset(trie,0,sizeof trie);
    }
    
    void ins(int x) {
        int cur = 0; sz[cur] ++;
        F0Rd(i,30) {
            int t = (x&(1<<i))>>i;
            if (!trie[cur][t]) trie[cur][t] = ++nex;
            cur = trie[cur][t]; sz[cur] ++;
        }
    }
    
    void del(int x) {
        int cur = 0; sz[cur] --;
        F0Rd(i,30) {
            int t = (x&(1<<i))>>i;
            if (!trie[cur][t]) trie[cur][t] = ++nex;
            cur = trie[cur][t]; sz[cur] --;
        }
    }
    
    void test(int x) {
        int cur = 0, z = 0;
        F0Rd(i,30) {
            int t = ((x&(1<<i))>>i);
            if (!trie[cur][t] || !sz[trie[cur][t]]) t ^= 1;
            cur = trie[cur][t];
            if (t) z ^= 1<<i;
        }
        del(z);
        cout << (x^z) << " ";
    }
};

tri<20000000> t;

int n, a[300000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    F0R(i,n) cin >> a[i];
    F0R(i,n) {
        int x; cin >> x;
        t.ins(x);
    }
    F0R(i,n) t.test(a[i]);
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)