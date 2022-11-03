#include <bits/stdc++.h>
using namespace std;

int GetAmountOfDigits(int x, int base)
{
    int res = 0;
    while (x > 0) {
        x /= base;
        ++res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ans = 0;

    long long n;
    cin >> n;

    for (long long i = 1; i <= n; i *= 10) {
        long long j = min(n, i * 10 - 1);

        ans += (j - i + 1) * GetAmountOfDigits(i, 10);
    }

    cout << ans << endl;


    return 0;
}