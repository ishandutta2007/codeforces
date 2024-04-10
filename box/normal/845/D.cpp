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

stack<int> stc;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int no_overtake_sign_count = 0;
    int n; cin >> n;
    int ans = 0, sp = 0;
    rep(i, n) {
        int op; cin >> op;
        if(op == 1) {
            cin >> sp;
            while(stc.size() && stc.top() < sp) {
                ans++;
                stc.pop();
            }
        } else if(op == 2) {
            ans += no_overtake_sign_count;
            no_overtake_sign_count = 0;
        } else if(op == 3) {
            int spl; cin >> spl;
            if(sp > spl) ans++;
            else stc.push(spl);
        } else if(op == 4) {
            no_overtake_sign_count = 0;
        } else if(op == 5) {
            while(stc.size()) stc.pop();
        } else if(op == 6) {
            no_overtake_sign_count++;
        }
    }
    cout << ans << endl;
}