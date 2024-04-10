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
    int o = 0; for(char& c:s) o += (c == '1');
    if(o == s.length()) cout << s.substr(1) << endl;
    else {
        for(const char& c:s) {
            if(c == '0') {
                if(o) o = 0;
                else cout << c;
            }
            else if(c == '1') cout << c;
        }
        cout << endl;
    }
}