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
    string s; cin >> s;
    int firstcolon = -2, lastcolon = -2;
    rep(i, s.length()) {
        if(s[i] == '[' && firstcolon == -2) firstcolon = -1;
        if(s[i] == ':' && firstcolon == -1) {
            firstcolon = i;
            break;
        }
    }
    for(int i=s.length()-1; i>=0; i--) {
        if(s[i] == ']' && lastcolon == -2) lastcolon = -1;
        if(s[i] == ':' && lastcolon == -1) {
            lastcolon = i;
            break;
        }
    }
    if(firstcolon < 0 || lastcolon < 0 || firstcolon >= lastcolon) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    iter(i, firstcolon+1, lastcolon) cnt += (s[i] == '|');
    cout << cnt+4 << endl;
}