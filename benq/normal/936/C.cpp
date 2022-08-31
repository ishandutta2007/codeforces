
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

int n;
string a,b;
vi ans;

/* set<vpi> res;

void prin(vpi x) {
    F0R(i,sz(x)) cout << x[i].f << " " << x[i].s << " | ";
    cout << "\n";
}

vpi des = {{1,0},{0,0},{2,1}};
vector<vpi> sta;

void search(vpi x, int cur) {
    if (x == des) {
        for (auto a: sta) prin(a);
        cout << "\n";
    }
    if (cur == 3) return;
    sta.pb(x);
    FOR(i,1,4) {
        vpi X; FORd(j,3-i,3) X.pb({x[j].f,x[j].s^1});
        F0R(j,3-i) X.pb(x[j]);
        search(X,cur+1);
    }
    sta.pop_back();
}*/

void rev(int x) {
    ans.pb(x);
    string A = a.substr(0,n-x), B = a.substr(n-x,x);
    reverse(all(B));
    a = B+A;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;
    
    string A = a, B = b;
    sort(all(A)), sort(all(B));
    
    if (A != B) {
        cout << -1;
        return 0;
    }
    
    F0R(i,n) {
        int j = i;
        while (a[j] != b[n-1-i]) j ++;
        rev(n), rev(j), rev(1);
    }
    
    cout << sz(ans) << "\n";
    for (int i: ans) cout << i << " ";
}

// read the question correctly (is y a vowel?)
// look out for special cases (n=1?) and overflow (ll vs int?)