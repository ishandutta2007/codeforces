#pragma GCC target("popcnt")
#pragma GCC target("tune=native")

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

int dp[1<<24];
uint8_t sbit[24];
int x[24], y[24];
int pt[24], dt[24][24];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    int n; cin >> n;
    rep(i, n) {
        cin >> x[i] >> y[i];
        x[i] -= a; y[i] -= b;
    }
    rep(i, n) {
        pt[i] = x[i]*x[i] + y[i]*y[i];
        iter(j, i+1, n) dt[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    }
    dp[0] = 0;
    iter(mask, 1, 1<<n) {
        int bes = 0x0fffffff, sbc = 0;
        rep(i, n)
            if(mask&(1<<i)) {
                sbit[sbc++] = i;
                bes = min(bes, dp[mask^(1<<i)] + 2*pt[i]);
            }
        if(sbc != 1)
            rep(i, sbc-1)
                iter(j, i+1, sbc) 
                    bes = min(bes, dp[mask^(1<<sbit[i])^(1<<sbit[j])] + pt[sbit[i]] + pt[sbit[j]] + dt[sbit[i]][sbit[j]]);
        dp[mask] = bes;
    }
    cout << dp[(1<<n)-1] << endl;
    int mask = (1<<n)-1;
    stack<pair<int, int>> at;
    while(mask) {
        int bes = 0x0fffffff, sbc = 0;
        int ba = -1, bb = 0;
        rep(i, n)
            if(mask&(1<<i)) {
                sbit[sbc++] = i;
                int k = dp[mask^(1<<i)] + 2*pt[i];
                if(k < bes) {
                    bes = k;
                    bb = i;
                }
            }
        if(sbc != 1)
            rep(i, sbc-1)
                iter(j, i+1, sbc) {
                    int k = dp[mask^(1<<sbit[i])^(1<<sbit[j])] + pt[sbit[i]] + pt[sbit[j]] + dt[sbit[i]][sbit[j]];
                    if(k < bes) {
                        bes = k;
                        ba = sbit[i]; bb = sbit[j];
                    }
                }
        at.push(mp(ba, bb));
        mask = mask ^ (1<<bb);
        if(ba != -1) mask = mask ^ (1<<ba);
    }
    cout << 0;
    while(at.size()) {
        auto v = at.top(); at.pop();
        if(v.fi != -1) cout << ' ' << v.fi+1 << ' ' << v.se+1;
        else cout << ' ' << v.se+1;
        cout << ' ' << 0;
    }
    cout << endl;
}