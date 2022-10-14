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

/*

(  )  (  )  )  )  (  )
1  0  1  0 -1 -2 -1 -2

(  )  (  (  (  )  (  )
1  0  1  2  3  2  3  2

)  )  )  (  (  (  (  (
-1 -2 -3 -2 -1 0  1  2

)  (  (  (
-1 0  1  2
*/

int psum[1000006];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep1(i, n) {
        char c; cin >> c;
        if(c == '(') psum[i] = 1;
        else psum[i] = -1;
        psum[i] += psum[i-1];
        if(psum[i] == -3) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    if(psum[n] == -2)
        rep1(i, n) {
            if(psum[i] - psum[i-1] == -1) ans++;
            if(psum[i] == -1) break;
        }
    else if(psum[n] == 2) 
        for(int i=n; i>=1; i--) {
            if(psum[i] == 1) {
                rep1(c, n) if(psum[c] == -1) ans = 0;
                break;
            }
            if(psum[i] - psum[i-1] == 1) ans++;
        }
    cout << ans << endl;
}