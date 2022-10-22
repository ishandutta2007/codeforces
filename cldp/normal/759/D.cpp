#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int C[MAXN][MAXN];
int f[MAXN][26], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    string P;
    cin >> N >> P;
    for (int i = 0; i <= N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % INF;
        C[i][i] = 1;
    }
    
    vector<int> Q;
    Q.push_back(P[0] - 'a');
    for (int i = 1; i < N; ++i) {
        if (P[i] == P[i - 1]) continue;
        Q.push_back(P[i] - 'a');
    }

    f[1][Q[0]] = 1;
    s[1] = 1;
    for (int i = 1; i < Q.size(); ++i) {
        s[1] = (s[1] - f[1][Q[i]] + INF) % INF;
        f[1][Q[i]] = 1;
        s[1] = (s[1] + 1) % INF;

        for (int j = i + 1; j >= 2; --j) {
            s[j] = (s[j] - f[j][Q[i]] + INF) % INF;
            f[j][Q[i]] = (s[j - 1] - f[j - 1][Q[i]] + INF) % INF;
            s[j] = (s[j] + f[j][Q[i]]) % INF;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= Q.size(); ++i) {
        long long cnt = 0;
        for (int j = 0; j < 26; ++j) cnt = cnt + f[i][j];
        cnt %= INF;
        ans = (ans + cnt * C[N - 1][i - 1]) % INF;
    }
    cout << ans << endl;

    return 0;
}