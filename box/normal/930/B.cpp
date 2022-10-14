// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

int has[26];
int oc[26];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; int cnt = 0;
    for(char c:s) {
        has[c-'a'] ++;
    } long double ans = 0;
    rep(i, 26) {
        long double prb = 0;
        rep(guess, s.length()) {
            memset(oc, 0, sizeof oc);
            int dst = 0, tot = 0;
            rep(shif, s.length()) {
                if(s[shif]-'a' != i) continue;
                tot++;
                oc[s[(shif+guess)%s.length()]-'a']++;
            }
            rep(dx, 26) dst += (oc[dx]==1);
            long double lprb = prb;
            prb = max(prb, (1.L*dst)/tot);
            
        }
        ans += prb*has[i]/s.length();
    }
    cout << fixed << setprecision(20) << ans << endl;
}