#include <bits/stdc++.h>

using namespace std;

int a[(int)2e5 + 10];
int b[(int)2e5 + 10];
int c[(int)2e5 + 10];
int d[(int)2e5 + 10];

int main()
{
    int n;
    cin >> n;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            q = i;
    }
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[q] > 0)
            c[t++] = a[q];
        q++;
        if (q == n)
            q = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            q = i;
    }
    t = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[q] > 0)
            d[t++] = b[q];
        q++;
        if (q == n)
            q = 0;
    }
    string ans = "YES";
    for (int i = 0; i < n - 1; i++)
    {
        if (c[i] != d[i])
            ans = "NO";
    }
    cout << ans << endl;
    return 0;
}