#include <bits/stdc++.h>
using namespace std;

const int N = 2025;
const int magic = 63;
const int mod = 998244353;

vector<int> v;
int cnt[N][N];
int dp[N][N];
int pd[2][N][N];
int n, K;

void solve() {
    if(v.size() == 1 && v[0] == 1) return;
    int ttt = 3;
    vector<int> new_v = v;
    while(true) {
        int l = 1;
        int sum = 0;
        for(int i = 0, j = new_v.size(); i < new_v.size(); i++, j--) {
            int r = l+new_v[i]-1;
            sum += j * (l+r) * (r-l+1)/2;
            if(sum >= N) return;
            l += new_v[i];
        }
        cnt[sum][ttt]++;
        vector<int> tmp;
        for(int i = (int)new_v.size()-1, j = 1; i >= 0; i--, j++) {
            int c = new_v[i];
            while(c--) {
                tmp.push_back(j);
            }
        }
        new_v = tmp;
        ttt++;
    }
}

void bktk(int cur, int sum, bool lastTaken) {
    if(lastTaken) {
        solve();
    }
    if(cur+sum > magic) return;
    for(int k = 0; sum + cur * k <= magic; k++) {
        if(k) v.push_back(cur);
        bktk(cur+1, sum+cur*k, k > 0);
    }
    while(v.size() > 0 && v.back() == cur) v.pop_back();
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;
    if(K >= 3) {
        bktk(1, 0, 0);
        int ans = 1;
        for(int i = 1; i <= n; i++) ans += cnt[i][K];
        cout << ans << endl;
    }
    else if(K == 1) {
        dp[0][0] = 1;
        for(int x = 1; x <= n; x++) {
            dp[x][0] = 1;
            for(int s = 1; s <= n; s++) {
                for(int k = 0; k * x <= s; k++) {
                    dp[x][s] += dp[x-1][s-k*x];
                    if(dp[x][s] >= mod) dp[x][s] -= mod;
                }
            }
        }
        int ans = 0;
        for(int s = 1; s <= n; s++) {
            ans += dp[n][s];
            if(ans >= mod) ans -= mod;
        }
        cout << ans << endl;
    }
    else {
        for(int x = 1; x <= n; x++) pd[0][0][x] = 1;
        int ans = 0;
        for(int pos = 1; pos <= magic; pos++) {
            for(int s = 0; s <= n; s++) for(int x = 0; x <= n; x++) pd[pos&1][s][x] = 0;
            for(int s = 1; s <= n; s++) {
                for(int x = n; x >= 1; x--) {
                    pd[pos&1][s][x] = pd[(pos&1)][s][x+1] + (s >= x*pos ? pd[(pos&1)^1][s-x*pos][x] : 0);
                    if(pd[pos&1][s][x] >= mod) pd[pos&1][s][x] -= mod;
                }
            }
            for(int s = 1; s <= n; s++) {
                ans += pd[pos&1][s][1];
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
}