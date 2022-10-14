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

ll a, b, N;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> a >> b;
    N *= 6;
    ll opt = 1000000000000000009ll;
    ll opta = -1, optb = -1;
    for(ll Y=0; Y<=1000000; Y++) {
        ll dt = max(0ll, (N-a*b-b*Y+a+Y-1)/(a+Y));
        ll t = a*b+(a+Y)*dt+b*Y;
        if(N <= t && t < opt) {
            opt = t;
            opta = a+Y;
            optb = b+dt;
        }
        dt = max(0ll, (N-a*b-a*Y+b+Y-1)/(b+Y));
        t = a*b+(b+Y)*dt+a*Y;
        if(N <= t && t < opt) {
            opt = t;
            optb = b+Y;
            opta = a+dt;
        }
    }
    cout << opt << endl;
    cout << opta << ' ' << optb << endl;
}