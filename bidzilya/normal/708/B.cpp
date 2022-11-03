#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
using namespace std;

const long long LIM = 1e6;

const string IMPOSSIBLE = "Impossible";

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

bool Solve(long long sum, long long& d) {
    if (!IsSquare(1 + 8 * sum, d)) {
        return false;
    }

    d += 1;

    if (d & 1) {
        return false;
    }

    d /= 2;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a[2][2];

    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];

    long long sum = a[0][0] + a[0][1] + a[1][0] + a[1][1];

    long long len;
    if (!Solve(sum, len) || len == 0) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    if (a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) {
        if (len * (len - 1) / 2 == a[0][0]) {
            for (int i = 0; i < len; ++i) {
                cout << '0';
            }
            cout << endl;
            return 0;
        } else {
            cout << IMPOSSIBLE << endl;
            return 0;
        }
    }

    if (a[0][0] == 0 && a[1][0] == 0 && a[0][1] == 0) {
        if (len * (len - 1) / 2 == a[1][1]) {
            for (int i = 0; i < len; ++i) {
                cout << '1';
            }
            cout << endl;
            return 0;
        } else {
            cout << IMPOSSIBLE << endl;
            return 0;
        }
    }

    long long zeroCount;
    if (!Solve(a[0][0], zeroCount) || zeroCount == 0) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    long long onesCount;
    if (!Solve(a[1][1], onesCount) || onesCount == 0) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    if (zeroCount + onesCount != len) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    long long needValue = a[1][0];

    long long prefixOnesCount = needValue / zeroCount;

    if (prefixOnesCount == onesCount) {
        for (int i = 0; i < onesCount; ++i) {
            cout << '1';
        }
        for (int i = 0; i < zeroCount; ++i) {
            cout << '0';
        }
        cout << endl;
        return 0;
    }

    if (prefixOnesCount > onesCount) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    long long lastOnesPos = needValue % zeroCount;

    string result;
    result.reserve(len);
    for (int i = 0; i < prefixOnesCount; ++i) {
        result.push_back('1');
    }

    if (lastOnesPos > 0 && prefixOnesCount == onesCount) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    for (int i = 0; i < zeroCount; ++i) {
        result.push_back('0');

        if (zeroCount - i - 1 == lastOnesPos) {
            result.push_back('1');
        }
    }

    for (int i = 0; i < onesCount - prefixOnesCount - 1; ++i) {
        result.push_back('1');
    }

    cout << result << endl;

    return 0;
}