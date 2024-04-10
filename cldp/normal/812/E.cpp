#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], d[MAXN];
vector<int> X[MAXN];
int maxd = 0, cnt = 0;
int XOR = 0;
map<int, int> S;
long long ans = 0;

void findd(int a, int depth) {
    d[a] = depth;
    maxd = max(maxd, depth);
    for (int i = 0; i < X[a].size(); ++i) findd(X[a][i], depth + 1);
}

void dfs(int a) {
    if (d[a] % 2 == maxd) {
        ++cnt;
        XOR = XOR ^ x[a];
    } else {
        ++S[x[a]];
    }
    for (int i = 0; i < X[a].size(); ++i) dfs(X[a][i]);
}

void addsame(int a) {
    if (d[a] % 2 == maxd) ans += S[x[a]];
    for (int i = 0; i < X[a].size(); ++i) addsame(X[a][i]);
}

void addchange(int a) {
    if (d[a] % 2 == maxd) {
        int temp = XOR ^ x[a];
        ans += S[temp];
    }
    for (int i = 0; i < X[a].size(); ++i) addchange(X[a][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x[i];
    for (int i = 2; i <= N; ++i) {
        int a;
        cin >> a;
        X[a].push_back(i);
    }
    findd(1, 0);
    maxd %= 2;
    dfs(1);

    if (XOR == 0) {
        ans = 1LL * cnt * (cnt - 1) / 2;
        cnt = N - cnt;
        ans += 1LL * cnt * (cnt - 1) / 2;
        addsame(1);
    } else {
        addchange(1);
    }
    cout << ans << endl;

    return 0;
}