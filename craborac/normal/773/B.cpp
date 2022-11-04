#include <bits/stdc++.h>
#define android ios

using namespace std;

int a[300][10], b[10];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(b, b + 5, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
            if (a[i][j] >= 0)
                b[j]++;
        }
    }
    vector<int> v;
    for (int j = 0; j < 5; j++)
    {
        if (a[0][j] <= a[1][j] || a[1][j] == -1)
        {
            long long x = b[j];
            if (x * 32 > n)
                v.push_back(x * 32 - n);
            if (x * 16 > n)
                v.push_back(16 * x - n);
            if (x * 8 > n)
                v.push_back(8 * x - n);
            if (x * 4 > n)
                v.push_back(4 * x - n);
            if (x * 2 > n)
                v.push_back(2 * x - n);
            if (x * 1 > n)
                v.push_back(1 * x - n);
        }
        else
        {
            long long x = b[j];
            if (x * 32 < n)
                v.push_back((n - 32 * x) / 31 + 1);
            if (x * 16 < n)
                v.push_back((n - 16 * x) / 15 + 1);
            if (x * 8 < n)
                v.push_back((n - 8 * x) / 7 + 1);
            if (x * 4 < n)
                v.push_back((n - 4 * x) / 3 + 1);
            if (x * 2 < n)
                v.push_back((n - 2 * x) / 1 + 1);
        }
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    for (int mi: v)
    {
        long long a1 = 0, a2 = 0;
        for (int j = 0; j < 5; j++)
        {
            if (a[0][j] <= a[1][j] || a[1][j] == -1)
            {
                long long x = b[j];
                long long y = 0;
                n += mi;
                if (x * 32 <= n)
                    y = 3000;
                else if (x * 16 <= n)
                    y = 2500;
                else if (x * 8 <= n)
                    y = 2000;
                else if (x * 4 <= n)
                    y = 1500;
                else if (x * 2 <= n)
                    y = 1000;
                else
                    y = 500;
                n -= mi;
                if (a[0][j] >= 0)
                    a1 += y - y * a[0][j] / 250;
                if (a[1][j] >= 0)
                    a2 += y - y * a[1][j] / 250;
            }
            else
            {
                long long x = b[j] + mi;
                long long y = 0;
                n += mi;
                if (x * 32 <= n)
                    y = 3000;
                else if (x * 16 <= n)
                    y = 2500;
                else if (x * 8 <= n)
                    y = 2000;
                else if (x * 4 <= n)
                    y = 1500;
                else if (x * 2 <= n)
                    y = 1000;
                else
                    y = 500;
                n -= mi;
                if (a[0][j] >= 0)
                    a1 += y - y * a[0][j] / 250;
                if (a[1][j] >= 0)
                    a2 += y - y * a[1][j] / 250;
            }
        }
        if (a1 > a2)
        {
            cout << mi << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}