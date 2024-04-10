#include <iostream>
#include <vector>
using namespace std;

long long GetGcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

struct TFrac {
    long long X;
    long long Y;

    TFrac()
        : X(0)
        , Y(1)
    {
    }

    TFrac(long long a, long long b)
        : X(a)
        , Y(b)
    {
        long long g = GetGcd(abs(a), abs(b));
        X /= g;
        Y /= g;
    }
};

TFrac operator - (const TFrac& lhs, const TFrac& rhs) {
    return TFrac(lhs.X * rhs.Y - rhs.X * lhs.Y, lhs.Y * rhs.Y);
}

TFrac operator + (const TFrac& lhs, const TFrac& rhs) {
    return TFrac(lhs.X * rhs.Y + rhs.X * lhs.Y, lhs.Y * rhs.Y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<vector<TFrac>> a(n);

    for (int i = 0; i < n; ++i) {
        a[i].resize(i + 1);
    }

    a[0][0] = TFrac(t, 1);

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (a[i][j].X > a[i][j].Y) {
                long long rem = a[i][j].X - a[i][j].Y;
                a[i][j].X = a[i][j].Y;

                TFrac c(rem, 2 * a[i][j].Y);
                a[i + 1][j] = a[i + 1][j] + c;
                a[i + 1][j + 1] = a[i + 1][j + 1] + c;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (a[i][j].X >= a[i][j].Y) {
                ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}