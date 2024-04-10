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

vector<string> s;
set<string> S2;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, n) {
        string t; cin >> t;
        s.pb(t);
        S2.insert(t);
    }
    string ans;
    rep(i, n) {
        string v = s[i];
        if(ans.length() > v.length()) continue;
        reverse(all(v));
        if(v == s[i]) ans = v;
    }
    rep(i, n) {
        string v = s[i];
        reverse(all(v));
        if(S2.count(s[i]) && S2.count(v) && S2.find(s[i]) != S2.find(v)) {
            ans = s[i] + ans + v;
            S2.erase(s[i]);
            S2.erase(v);
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}