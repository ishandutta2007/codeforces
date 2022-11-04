#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, t, k, d;
    cin >> n >> t >> k >> d;
    long long a = ((n + k - 1) / k) * t;
    long long le = 0, ri = (long long)1e6 + 1;
    while (ri - le > 1)
    {
        long long mi = (le + ri) / 2;
        long long b = (mi / t) * k;
        if (mi >= d)
            b += ((mi - d) / t) * k;
        if (b >= n)
            ri = mi;
        else
            le = mi;
    }
    if (ri < a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}