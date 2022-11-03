#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

inline void ModMult(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMult(int x, int y) {
    ModMult(x, y);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    vector<int> d[2];
    d[0].assign(n, 0);
    d[1].assign(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        d[0][i] = h[i] - 1;
        if (i + 1 < n) {
            int th = min(h[i] - 1, h[i + 1] - 1);
            ModSum(d[0][i], GetModMult(th, d[1][i + 1]));
        }

        if (i != 0) {
            int th = min(h[i] - 1, h[i - 1] - 1);
            d[1][i] = th;
            if (i + 1 < n) {
                th = min(th, h[i + 1] - 1);
                ModSum(d[1][i], GetModMult(th, d[1][i + 1]));
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        ModSum(result, d[0][i]);
    }
    cout << result << endl;

    return 0;
}