#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int N = 5007;
const int Q = 507;
const double EPS = 1e-8;

int dp[N][Q], pred[N][Q];

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            dp[i][j] = -1;
        }
    }
    int d, s;
    cin >> d >> s;
    queue <pair <int, int> > q;
    for (int j = 1; j < 10; j++) {
        q.push({j, j % d});
        dp[j][j % d] = j;
        pred[j][j % d] = 0;
    }
    while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        q.pop();
        for (int i = 0; i < 10; i++) {
            int a1 = a + i;
            int b1 = (10 * b + i) % d;
            if (dp[a1][b1] != -1 || a1 > s) continue;
            dp[a1][b1] = i;
            pred[a1][b1] = b;
            q.push({a1, b1});
        }
    }
    if (dp[s][0] == -1) {
        cout << -1;
        return 0;
    }
    string res = "";
    int a = s, b = 0;
    while (a) {
        int k = dp[a][b];
        int p = pred[a][b];
        b = p;
        a -= k;
        res += (char) (k + '0');
    }
    reverse(res.begin(), res.end());
    cout << res;
}