#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n;

    long long x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        long long tl = 0;
        long long tr = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 100;

        long long ta = tr;
        while (tl <= tr) {
            long long tm = (tl + tr) >> 1;

            long long cnt = tm / x + tm / y;
            if (cnt >= a) {
                ta = tm;
                tr = tm - 1;
            } else {
                tl = tm + 1;
            }
        }

        if (ta % x == 0 && ta % y == 0) {
            cout << "Both" << '\n';
        } else if (ta % x == 0) {
            cout << "Vova" << '\n';
        } else {
            cout << "Vanya" << '\n';
        }
    }

    return 0;
}