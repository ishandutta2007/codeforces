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

int ans[10][10];
int BIAO[10][10][10];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    rep(dt, 10)
        rep(s, 10)
            rep(t, 10) {
                BIAO[dt][s][t] = 100;
                rep(i, 10)
                    rep(j, 10)
                        if((i+j) && dt == (i*s + j*t)%10) BIAO[dt][s][t] = min(BIAO[dt][s][t], i+j-1);
                if(BIAO[dt][s][t] == 100) BIAO[dt][s][t] = -1;
            }
    string s; cin >> s;
    memset(ans, 0, sizeof ans);
    iter(i, 1, s.length()) {
        int dt = (10 + s[i] - s[i-1]) % 10;
        rep(s, 10)
            rep(t, 10) {
                if(ans[s][t] == -1 || BIAO[dt][s][t] == -1) ans[s][t] = -1;
                else ans[s][t] += BIAO[dt][s][t];
            }
    }
    rep(s, 10) {
        rep(t, 10) {
            if(t) cout << ' ';
            cout << ans[s][t];
        }
        cout << endl;
    }
}