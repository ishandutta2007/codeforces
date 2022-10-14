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
    int a = 0, b = 0;
    for(const char& c:s) a += (1-2*(c=='-'));
    cin >> s;
    for(const char& c:s) {
        if(c == '?') b++;
        else a += (1-2*(c=='+'));
    }
    // b adds must become a
    // x - y = a
    // x + y = b
    // 2x = a + b
    if((a+b)%2 || (a+b < 0) || (b < a)) { cout << "0.0" << endl; return 0; }
    int pl = (a+b)/2;
    ll cn = 1; 
    rep1(i, b) cn *= i;
    rep1(i, pl) cn /= i;
    rep1(i, b-pl) cn /= i;
    long double v = cn;
    rep1(i, b) v /= 2;
    cout << fixed << setprecision(20) << v << endl;
}