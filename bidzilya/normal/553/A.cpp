#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

inline void ModInc(int& x, int y)
{
    x += y;
    if (x >= kMod) {
        x -= kMod;
    }
    if (x < 0) {
        x += kMod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<int> c(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
    }

    const int kMaxC = 1111;

    vector<vector<int> > C(kMaxC, vector<int>(kMaxC));
    C[0][0] = 1;
    for (int i = 1; i < kMaxC; ++i) {
        C[i][0] = 1;
    }
    for (int j = 1; j < kMaxC; ++j) {
        C[0][j] = 0;
    }
    for (int i = 1; i < kMaxC; ++i) {
        for (int j = 1; j < kMaxC; ++j) {
            C[i][j] = C[i - 1][j];
            ModInc(C[i][j], C[i - 1][j - 1]);
        }
    }

    int res = 1;
    int sum = 0;
    for (int i = 1; i <= k; ++i) {
        res = (1LL * res * C[c[i] - 1 + sum][c[i] - 1]) % kMod;
        sum += c[i];
    }

    cout << res << endl;


    return 0;
}