
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

string s,t;
vector<array<int,3>> S, T;
vi ans;

void ad(int x) { ans.pb(x); }
void ad(int x, int y) { ans.pb(x), ans.pb(y); }

vector<array<int,3>> compress(string s) {
    vector<array<int,3>> v;
    for (int i = 0; i < sz(s); ) {
        int I = i;
        while (i < sz(s) && s[i] == s[I]) i ++;
        v.pb({s[I]-'a',I,i-I});
    }
    return v;
}

int closeOdd(int x) {
    if (x < 0) return -closeOdd(-x);
    // 0: 1, 1: 1, 2: 1, 3: 1, 4: 1
    // if (x % 4 == 3) return 2*(x/4)+3;
    if (x % 4 == 0) return 2*(x/4)-1;
    return 2*(x/4)+1;
}

int closeEven(int x) {
    if (x < 0) return -closeEven(-x);
    // 0: 0, 1: 0, 2: 0, 3: 2, 4: 2, 
    if (x % 4 <= 2) return 2*(x/4);
    return 2*(x/4)+2;
}

vector<array<int,3>> extract(vector<array<int,3>>& a, int z) {
    vector<array<int,3>> tmp;
    ad (z == sz(a) ? a[z-1][1]+a[z-1][2] : a[z][1]);
    while (sz(a) > z) tmp.pb(a.back()), a.pop_back();
    reverse(all(tmp)); 
    if (sz(tmp)) {
        int st = tmp[0][1];
        for (auto& x: tmp) x[1] -= st;
    }
    return tmp;
}

void merge(vector<array<int,3>>& a, vector<array<int,3>> b) {
    if (sz(a) == 0) {
        a = b;
        return;
    }
    for (auto x: b) {
        if (a.back()[0] == x[0]) {
            a.back()[2] += x[2];
        } else {
            x[1] = a.back()[1]+a.back()[2];
            a.pb(x);
        }
    }
}

void prin(vector<array<int,3>> v) {
    for (auto a: v) F0R(j,a[2]) cout << char('a'+a[0]);
    cout << "\n----\n";
}

int co = 0;

void finish() {
    cout << sz(ans)/2 << "\n";
    F0R(i,sz(ans)/2) cout << ans[2*i] << " " << ans[2*i+1] << "\n";
    exit(0);
}

void dosmth() {
    // cout << "AH " << sz(S) << " " << sz(T) << "\n";
    if (sz(S) == 1 && sz(T) == 2) {
        if (S[0][0] == T[0][0]) {
            // a, ab 
            ad(0,T[0][2]);
        } else {
            ad(S[0][2],T[0][2]);
        }
        finish();
    }
    if (sz(T) == 1 && sz(S) == 2) {
        if (S[0][0] == T[0][0]) {
            ad(S[0][2],0);
            // a, ab 
        } else {
            // a, ba
            ad(S[0][2],T[0][2]);
        }
        finish();
    }
    if (S[0][0] == T[0][0]) {
        if ((sz(S) == 1 && sz(T) > 3) && sz(S) < sz(T)) {
            ad(0);
            auto TT = extract(T,3);
            merge(T,S); S = TT;
            swap(S,T);
            //prin(S); prin(T);
        } else if ( (sz(S) > 3 && sz(T) == 1) && sz(S) > sz(T)) {
            auto SS = extract(S,3);
            merge(S,T); T = SS;
            ad(0);
            swap(S,T);
        }
        /*prin(S), prin(T);
        exit(0);*/
        // return;
    }
    
    int besdif,l,r;
    if (S[0][0] == T[0][0]) besdif = closeOdd(sz(S)-sz(T));
    else besdif = closeEven(sz(S)-sz(T));
    // cout << "AH " << besdif << "\n";
    l = 1+max(0,-besdif); // a+besdif
    r = min(sz(T),sz(S)-besdif)-1; // a 
    
    /*cout << besdif << " " << l << " " << r << "\n";
    exit(0);*/
    /*co ++;
    if (co == 100) exit(0);
    prin(S); prin(T);*/
    
    if (r < l) r ++;
    assert(l <= r);
    auto SS = extract(S,r+besdif), TT = extract(T,r);
    merge(S,TT), merge(T,SS); swap(S,T);
    // cout << "\n";
    // 1 <= a+besdif < sz(S)
    // 1 <= a < sz(T)
}

bool done() {
    if (max(sz(S),sz(T)) > 1) return 0;
    if (sz(S) && sz(T) && S[0][0] == T[0][0]) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    S = compress(s), T = compress(t);
    while (!done()) dosmth();
    finish();
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
*/