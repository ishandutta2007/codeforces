#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n == 0) {
        long long x = sum / n;
        long long needDown = 0;
        long long needUp = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= x) {
                needUp += a[i] - x;
            } else {
                needDown += x - a[i];
            }
        }
        if (needDown == needUp && needDown <= k) {
            cout << 0 << endl;
            return 0;
        }
    }

    sort(a.begin(), a.end());

    long long L;
    {
        L = a[0];
        sum = 0;
        for (int i = 1; i < n; ++i) {
            long long newSum = sum + (a[i] - a[i - 1]) * i;

            if (newSum <= k) {
                sum = newSum;
                L = a[i];
            } else {
                long long x = (k - sum) / i;

                L = a[i - 1] + x;
                break;
            }
        }
    }

    long long R;
    {
        R = a[n - 1];
        sum = 0;
        for (int i = n - 2; i >= 0; --i) {
            long long newSum = sum + (a[i + 1] - a[i]) * (n - i - 1);

            if (newSum <= k) {
                sum = newSum;
                R = a[i];
            } else {
                long long x = (k - sum) / (n - i - 1);

                R = a[i + 1] - x;
                break;
            }
        }
    }

    if (R - L <= 1) {
        cout << 1 << endl;
        return 0;
    }

    cout << R - L << endl;
    return 0;
}