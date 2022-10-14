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

set<int> st;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep(i, n) {
        int v; cin >> v;
        st.insert(v);
    }
    bool have = false;
    int ans = -1, dt = -1;
    for(const int& v:st)
        rep(bt, 31) {
            if(st.count(v+(1ll<<bt)) && st.count(v+(2ll<<bt))) {
                have = true;
                ans = v; dt = bt;
                break;
            }
        }
    if(have) {
        cout << 3 << endl << ans << ' ' << (ans+(1ll<<dt)) << ' ' << (ans+(2ll<<dt)) << endl;
        return 0;
    }
    for(const int& v:st)
        rep(bt, 31) {
            if(st.count(v+(1ll<<bt))) {
                have = true;
                ans = v; dt = bt;
                break;
            }
        }
    if(have) {
        cout << 2 << endl << ans << ' ' << (ans+(1ll<<dt)) << endl;
    } else cout << 1 << endl << *st.begin() << endl;
}