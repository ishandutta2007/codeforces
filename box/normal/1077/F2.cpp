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

#define int ll

struct monoq {
    deque<int> data, mono; int dt;
    void clear() { data.clear(); mono.clear(); dt = 0; }
    int size() { return data.size(); }
    void addall(int val) { dt += val; }
    void push(int val) {
        val -= dt; data.push_back(val);
        while(mono.size() && mono.back() < val) mono.pop_back();
        mono.push_back(val);         // ^^^ change to < for max
    }
    void pop() { if(mono.front() == data.front()) { mono.pop_front(); } data.pop_front(); }
    int front() { return data.front() + dt; }
    int min() { return mono.front() + dt; }
} dq[5005];

int dp[5005][5005]; // dp[pic #][# of pics posted]
int val[5005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    rep(i, n) cin >> val[i];
    memset(dp, 0xaf, sizeof dp);
    int opt = 0xafafafafafafafafll;
    rep(i, n) {
        rep1(c, m) {
            if(i <= k-1 && c == 1) dp[i][c] = val[i];
            else if(i && c != 1) dp[i][c] = dq[c-1].min() + val[i];
            if(c == m && n-k <= i) opt = max(opt, dp[i][c]);
        }
        rep1(c, m-1) {
            if(dq[c].size() == k) dq[c].pop();
            dq[c].push(dp[i][c]);
        }
    }
    cout << max(-1ll, opt) << endl;
}