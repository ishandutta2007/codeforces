#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int GetBinaryPow(int x, int pw)
{
    if (pw == 0) {
        return 1;
    }
    if (pw & 1) {
        return (1LL * x * GetBinaryPow(x, pw - 1)) % MOD;
    }
    return GetBinaryPow((1LL * x * x) % MOD, pw >> 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, k;
    cin >> p >> k;

    if (k == 0) {
        cout << GetBinaryPow(p, p - 1) << endl;
        return 0;
    }

    if (k == 1) {
        cout << GetBinaryPow(p, p) << endl;
        return 0;
    }

    vector<bool> used(p, false);
    used[0] = true;
    int ans = 1;
    for (int s = 0; s < p; ++s) {
        if (used[s]) {
            continue;
        }
        int sz = 0;
        while (!used[s]) {
            used[s] = true;
            ++sz;
            s = (1LL * s * k) % p;
        }
        ans = (1LL * ans * p) % MOD;
    }
    cout << ans << endl;

    return 0;
}