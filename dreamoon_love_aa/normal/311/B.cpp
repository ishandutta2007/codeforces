#include<iostream>
#include<vector>
#include<algorithm>
using LL = long long;
using namespace std;
const int MAX_N = 100001;
const int MAX_P = 101;
LL dp[MAX_P][MAX_N];
vector<LL> s;
int stk[MAX_N];
void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    p = min(p, m);
    vector<int> d(n + 1);
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        d[i] = d[i - 1] + x;
    }
    vector<LL> a(m);
    for(auto &v: a) {
        int h, t;
        cin >> h >> t;
        v = t - d[h];
    }
    sort(a.begin(), a.end());
    a.insert(a.begin(), 0);
    s.resize(m + 1);
    for(int i = 1; i < (int)a.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= m; i++) dp[1][i] = a[i] * i - s[i];
    for(int i = 2; i <= p; i++) {
        int sl = 0, sn = 0;
        vector<LL> c(m + 1);
        for(int j = i - 1; j <= m; j++) c[j] = s[j] + dp[i - 1][j];
        stk[sn++] = i - 1;
        for(int j = i; j <= m; j++) {
            while(sl + 1 < sn && -stk[sl] * a[j] + c[stk[sl]] >= -stk[sl + 1] * a[j] + c[stk[sl + 1]]) sl++;
            dp[i][j] = dp[i - 1][stk[sl]] + a[j] * (j - stk[sl]) - (s[j] - s[stk[sl]]);
            while(sn > sl + 1 && (c[stk[sn - 1]] - c[stk[sn - 2]]) * (j - stk[sn - 1])
                              >= (c[j] - c[stk[sn - 1]]) * (stk[sn - 1] - stk[sn - 2])) sn--;
            stk[sn++] = j;
        }
    }
    cout << dp[p][m] << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}