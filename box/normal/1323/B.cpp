// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

vector<int> a, b;
int n, m;

ll answer(int x, int y) {
    int ba = 0, bs = 0, bsiz = 0;
    rep(i, m) {
        bs += b[i];
        bsiz++;
        ba += (bs == y);
        if(bsiz == y) {
            bs -= b[i-y+1];
            bsiz--;
        }
    }
    ll ans = 0;
    bs = 0, bsiz = 0;
    rep(i, n) {
        bs += a[i];
        bsiz++;
        ans += ba * (bs == x);
        if(bsiz == x) {
            bs -= a[i-x+1];
            bsiz--;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> n >> m >> k;
    rep(i, n) { int v; cin >> v; a.pb(v); }
    rep(i, m) { int v; cin >> v; b.pb(v); }
    ll ans = 0;
    rep1(i, min(k, n)) {
        if(k % i) continue;
        if(k/i > m) continue;
        ans += answer(i, k/i);
    }
    cout << ans << endl;
}