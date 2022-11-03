#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

bool IsSquare(long long x, long long& y) {
    y = sqrt(x);
    while (y * y < x) {
        ++y;
    }
    while (y * y > x) {
        --y;
    }
    return y * y == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> t(n + 1);

    for (int i = 1; i <= n; ++i) {
        t[i] = 1LL * i * (i + 1) * (i + 1) - (i == 1 ? 2 : (i - 1));

        cout << t[i] << '\n';
    }
    cout.flush();

    /*
    long long start = 2;
    for (int i = 1; i <= n; ++i) {
        start += 1LL * i * t[i];

        long long sq;
        if (!IsSquare(start, sq)) {
            cout << "FAIL" << endl;
            return 0;
        }

        start = sq;

        if (start % (i + 1) != 0) {
            cout << "FAIL" << endl;
            return 0;
        }
    }
    */

    return 0;
}