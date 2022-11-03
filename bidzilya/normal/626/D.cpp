#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

inline int GetSum(const vector<int>& s, int l, int r) {
    l = max(l, 0);
    r = min(r, (int) s.size() - 1);
    if (l > r) {
        return 0;
    }
    return ((l == 0) ? s[r] : s[r] - s[l - 1]);
}

int main() {
    /*
    freopen("input.txt", "w", stdout);
    const int N = 2000;
    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
    freopen("input.txt", "r", stdin);
    */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    const int MAX_A = 5e3;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> delta(MAX_A, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ++delta[a[i] - a[j]];
        }
    }

    vector<long long> doubleDelta(2 * MAX_A, 0);
    for (int i = 0; i < MAX_A; ++i) {
        for (int j = 0; j < MAX_A; ++j) {
            doubleDelta[i + j] += delta[i] * delta[j];
        }
    }

    long long result = 0;
    for (int i = 0; i < 2 * MAX_A; ++i) {
        for (int j = i + 1; j < MAX_A; ++j) {
            result += doubleDelta[i] * delta[j];
        }
    }

    long long buf = 1LL * n * (n - 1) / 2;
    long long all = buf * buf * buf;

    cout << fixed << setprecision(15) << 1.0 * result / all << endl;

    return 0;
}