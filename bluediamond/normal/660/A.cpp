#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

const int N = 2000 + 7;
int n;
int a[N];
int m;
int b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (m && gcd(a[i], b[m]) > 1)
        {
            b[++m] = 1;
        }
        b[++m] = a[i];
    }
    cout << m - n << "\n";
    for (int i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";

}