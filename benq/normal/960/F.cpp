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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

int N, M;
set<pi> dp[100001];
 
void ad(int a, int b, int e) {
    auto it = prev(dp[a].lb({e,-MOD}));
    pi des = {e,it->s+1};
    if (prev(dp[b].ub({e,MOD}))->s >= des.s) return;
    dp[b].insert(des);
    while (1) {
        auto it = dp[b].ub(des);
        if (it != dp[b].end() && des.s >= it->s) dp[b].erase(it);
        else return;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; 
    FOR(i,1,N+1) dp[i].insert({-1,0});
    F0R(i,M) {
        int a,b,e; cin >> a >> b >> e;
        ad(a,b,e);
    }
    int ans = 0;
    FOR(i,1,N+1) ans = max(ans,dp[i].rbegin()->s);
    cout << ans;
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)