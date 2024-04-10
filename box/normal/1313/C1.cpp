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

vector<int> m;
int n;
int an[1005];

ll test(int turndown, bool se) {
    int cur = m[turndown]; ll ans = m[turndown];
    if(se) an[turndown] = cur;
    for(int i=turndown-1; i>=0; i--) {
        cur = min(cur, m[i]);
        if(se) an[i] = cur;
        ans += cur;
    }
    cur = m[turndown];
    for(int i=turndown+1; i<n; i++) {
        cur = min(cur, m[i]);
        if(se) an[i] = cur;
        ans += cur;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, n) {
        int v; cin >> v;
        m.pb(v);
    }
    ll bes = -1; int optp = -1;
    rep(i, n) {
        ll k = test(i, 0);
        if(bes < k) {
            optp = i;
            bes = k;
        }
    }
    test(optp, 1);
    rep(i, n) {
        if(i) cout << ' ';
        cout << an[i];
    }
    cout << endl;
}