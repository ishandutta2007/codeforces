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

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        vector<int> e, o;
        int n; cin >> n;
        rep1(i, n) {
            int v; cin >> v;
            if(v%2) o.pb(i);
            else e.pb(i);
        }
        if(e.size()) cout << 1 << '\n' << e[0] << endl;
        else if(o.size() >= 2) cout << 2 << '\n' << o[0] << ' ' << o[1] << endl;
        else cout << -1 << endl;
    }
}