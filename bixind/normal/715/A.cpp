#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, i, a, b;
    cin >> n;
    a = 2;
    for (i = 1; i <= n; i++)
    {
        b = (i * (i + 1) * (i + 1)) - a / i;
        cout << b << endl;
        a = i * (i + 1);
    }
    return 0;
}