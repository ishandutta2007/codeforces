#include <iostream>
#include <vector>
using namespace std;

inline long long GetSQR(long long x) {
    return x * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x1, y1, x2, y2;

    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    x.push_back(x1);
    y.push_back(y1);

    x.push_back(x2);
    y.push_back(y2);

    n += 2;

    long long result = 1e18;
    for (int i = 0; i < n; ++i) {
        long long r1 = GetSQR(x[i] - x1) + GetSQR(y[i] - y1);
        long long r2 = 0;
        for (int j = 0; j < n; ++j) {
            long long cR1 = GetSQR(x[j] - x1) + GetSQR(y[j] - y1);

            if (cR1 > r1) {
                r2 = max(r2, GetSQR(x[j] - x2) + GetSQR(y[j] - y2));
            }
        }
        result = min(result, r1 + r2);
    }

    cout << result << endl;

    return 0;
}