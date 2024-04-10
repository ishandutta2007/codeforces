#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

inline int GetCount(int x, int p) {
    return x / p;
}

inline int GetCount(int l, int r, int p) {
    return GetCount(r, p) - GetCount(l - 1, p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1 == n ? 0 : i + 1);

        int countLeft = r[i] - l[i] + 1;
        int countRight = r[j] - l[j] + 1;

        int resultCountLeft = GetCount(l[i], r[i], p);
        int resultCountRight = GetCount(l[j], r[j], p);

        long long allResultCount = 1LL * countLeft * resultCountRight +
                                   1LL * countRight * resultCountLeft -
                                   1LL * resultCountLeft * resultCountRight;
        long long allCount = 1LL * countLeft * countRight;

        double prob = 1.0 * allResultCount / allCount;

        result += 2000.0 * prob;
    }

    cout << fixed << setprecision(15) << result << endl;

    return 0;
}