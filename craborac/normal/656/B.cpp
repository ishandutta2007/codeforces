#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long c = b;
        b = a % b;
        a = c;
    }
    return a;
}

long long a[300], b[300];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long q = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        q = (q * a[i]) / gcd(q, a[i]);
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    long long ans = 0;
    for (long long i = 0; i < q; i++)
    {
        bool d = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i % a[j]) == b[j])
                d = 1;
        }
        if (d)
            ans++;
    }
    cout.precision(20);
    cout << (double)ans / q << endl;
    return 0;
}