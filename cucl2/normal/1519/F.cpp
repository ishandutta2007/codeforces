#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxk = 20005;
int n, m;
int a[7], b[7];
int c[7][7];
int dp[7][maxk];
int mii[7];

vector<int> inline decode(int x) {
    vector<int> res;
    loop(i, m) res.pub(x % 5), x /= 5;
    return res;
}

int inline encode(const vector<int> &x) {
    int res = 0;
    range(i, m - 1, 0, -1) res = res * 5 + x[i];
    return res;
}

void inline dfs(int i, vector<int> arr, int val, int now, int cst, int rem) {
    if (now == m) {
        if (rem) return;
        int id = encode(arr);
        dp[i + 1][id] = min(dp[i + 1][id], val + cst);
        return;
    }
    dfs(i, arr, val, now + 1, cst, rem);
    loop(j, min(arr[now], rem) + 1) {
        arr[now] -= j;
        dfs(i, arr, val, now + 1, cst + c[i][now], rem - j);
        arr[now] += j;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    loop(i, n) scanf("%d", a + i);
    loop(i, m) scanf("%d", b + i);
    loop(i, n) loop(j, m) scanf("%d", c[i] + j);
    mii[0] = 1;
    cont(i, m) mii[i] = 5 * mii[i - 1];
    int ini = encode(vector<int>(b, b + m));
    memset(dp, Inf, sizeof(dp));
    dp[0][ini] = 0;
    loop(i, n) loop(j, mii[m]) {
        if (dp[i][j] >= Inf) continue;
        vector<int> arr = decode(j);
        dfs(i, arr, dp[i][j], 0, 0, a[i]);
    }
    int ans = *min_element(dp[n], dp[n] + maxk);
    printf("%d\n", ans == Inf ? -1 : ans);
    return 0;
}

// 