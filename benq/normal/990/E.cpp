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
const int MX = 1000001;

int n,m,k,A[MX],lst[MX];
ll ans = INF;

ll test(int x) {
    int cur = 0, need = 0;
    while (1) {
        int CUR = cur;
        cur += x; need ++;
        if (cur >= n) return (ll)need*A[x];
        cur = lst[cur];
        if (CUR >= cur) return INF;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    F0R(i,n) lst[i] = i;
    F0R(i,m) {
        int S; cin >> S;
        lst[S] = -MOD;
    }
    if (lst[0] == -MOD) {
        cout << -1;
        exit(0);
    }
    FOR(i,1,n) lst[i] = max(lst[i],lst[i-1]);
    FOR(i,1,k+1) {
        cin >> A[i];
        ans = min(ans,test(i));
    }
    if (ans == INF) cout << -1;
    else cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS