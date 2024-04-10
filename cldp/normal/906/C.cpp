#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 25;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];
int f[1 << 22], g[1 << 22];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) x[i] = (1 << i);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        x[a] |= (1 << b);
        x[b] |= (1 << a);
    }

    bool flag = true;
    for (int i = 0; i < N; ++i) {
        if (x[i] != (1 << N) - 1) flag = false;
    }
    if (flag) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        f[1 << i] = x[i];
        g[1 << i] = i;
        if (x[i] == (1 << N) - 1) {
            cout << 1 << endl << i + 1 << endl;
            return 0;
        }
    }

    int ans = (1 << N) - 1;
    for (int i = 1; i < (1 << N); ++i) {
        if (__builtin_popcount(i) == 1) continue;

        for (int j = 0; j < N; ++j) {
            if ((i & (1 << j)) == 0) continue;
            if ((f[i ^ (1 << j)] & (1 << j)) == 0) continue;

            int temp = f[i ^ (1 << j)] | x[j];
            if (__builtin_popcount(temp) > __builtin_popcount(f[i])) {
                f[i] = temp;
                g[i] = j;
            }
        }
        if (f[i] == (1 << N) - 1 && __builtin_popcount(i) < __builtin_popcount(ans)) {
            ans = i;
        }
    }
    cout << __builtin_popcount(ans) << endl;
    vector<int> ansT;
    while (ans != 0) {
        ansT.push_back(g[ans]);
        ans -= (1 << g[ans]);
    }
    for (int i = ansT.size() - 1; i >= 0; --i) cout << ansT[i] + 1 << " ";
    cout << endl;

    return 0;
}