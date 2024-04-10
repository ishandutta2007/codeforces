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

int m, n;
int a[200005], b[200005];
int dis[200005];
int dp[200005]; // dp[i]: Position i, max last uncolored position

bool check(int t) {
    // First line goes <-
    int fans = a[1] - t + m;
    memset(dp, 0, sizeof(dp));
    dp[1] = a[1] + 1;
    circ(i, 2, n) {
        // Place <-
        if (dp[i - 1] >= a[i] - t) dp[i] = max(dp[i], max(dp[i - 1], a[i] + 1));
        // Place ->
        if (dp[i - 1] < a[i]) dp[i] = max(dp[i], dp[i - 1]);
        else dp[i] = max(dp[i], a[i] + t + 1);
        // i - 1 place ->, i place <-
        if (dp[i - 2] >= a[i] - t) dp[i] = max(dp[i], max(a[i - 1] + t + 1, a[i] + 1));
    }
    if (dp[n] >= fans) return 1;
    // First line goes ->, second line goes <-
    memset(dp, 0, sizeof(dp));
    fans = min(a[2] - t + m, a[1] + m);
    dp[2] = max(a[1] + t + 1, a[2] + 1);
    circ(i, 3, n) {
        // Place <-
        if (dp[i - 1] >= a[i] - t) dp[i] = max(dp[i], max(dp[i - 1], a[i] + 1));
        // Place ->
        if (dp[i - 1] < a[i]) dp[i] = max(dp[i], dp[i - 1]);
        else dp[i] = max(dp[i], a[i] + t + 1);
        // i - 1 place ->, i place <-
        if (dp[i - 2] >= a[i] - t) dp[i] = max(dp[i], max(a[i - 1] + t + 1, a[i] + 1));
    }
    if (dp[n] >= fans) return 1;
    return 0;
}

int main() {
    scanf("%d%d", &m, &n);
    cont(i, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    cont(i, n) {
        dis[i] = a[i % n + 1] - a[i];
        if (dis[i] < 0) dis[i] += m;
    }
    int pos = max_element(dis + 1, dis + n + 1) - dis - 1;
    cont(i, n) b[i] = dis[(i + pos - 1) % n + 1];
    cont(i, n) a[i] = a[i - 1] + b[i];
    int l = -1, r = m;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    printf("%d\n", r);
    return 0;
}