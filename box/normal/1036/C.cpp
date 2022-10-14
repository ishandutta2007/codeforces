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

int swdp[21][10][2][4]; // swdp[cdig][digit val][eq to q][nonzero]

int _solve_swdp(ll v) {
    if(v == 0) return 1;
    stack<int> let; while(v) { let.push(v%10); v /= 10; }
    vector<int> s; while(let.size()) { s.pb(let.top()); let.pop(); }
    memset(swdp, 0, sizeof swdp);
    swdp[0][s[0]][1][s[0] != 0] = 1;
    // change to 0 if can have preceding zeroes
    iter(d, 0, s[0]) swdp[0][d][0][d != 0] = 1;
    rep1(dig, s.size()-1) {
        rep(pdval, 10) rep(dval, 10)
            rep(d, 4) if(d || !dval) swdp[dig][dval][0][d] += swdp[dig-1][pdval][0][d - (dval != 0)];
        rep(dval, s[dig])
            rep(d, 4) if(d || !dval) swdp[dig][dval][0][d] += swdp[dig-1][s[dig-1]][1][d - (dval != 0)];
        rep(d, 4) if(d || !s[dig]) swdp[dig][s[dig]][1][d] += swdp[dig-1][s[dig-1]][1][d - (s[dig] != 0)];
    }
    int ans = 0; 
    rep(cnt, 4) rep(dval, 10) ans += swdp[s.size()-1][dval][0][cnt] + swdp[s.size()-1][dval][1][cnt];
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    rep(i, t) {
        ll a, b; cin >> a >> b;
        cout << _solve_swdp(b) - _solve_swdp(a-1) << endl;
    }
}