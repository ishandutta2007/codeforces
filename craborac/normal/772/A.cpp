#include <bits/stdc++.h>
#define android ios

using namespace std;

long double eps = (long double)1e-5;
long long a[(int)1e5 + 10];
long long b[(int)1e5 + 10];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long p;
    cin >> n >> p;
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        s += a[i];
    }
    double le = 0, ri = 1e18;
    if (s <= p)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int qwe = 0; qwe < 300; qwe++)
    {
        double mi = (le + ri) / 2;
        long double t = 0;
        for (int i = 0; i < n; i++)
        {
            t += max((double)0, mi * a[i] - b[i]);
        }
        if (t <= mi * p + eps)
            le = mi;
        else
            ri = mi;
    }
    cout.precision(20);
    cout << le << endl;
    return 0;
}