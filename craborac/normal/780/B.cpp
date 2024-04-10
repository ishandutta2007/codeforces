#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> mas[60010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mas[i].first;
    for (int i = 0; i < n; i++)
        cin >> mas[i].second;
    long double le = 0, ri = 1000000000 + 1;
    for (int qwe = 0; qwe < 100; qwe++)
    {
        long double m = (le + ri) / 2;
        long double x = -1000000000 * (long double)1000000000 - 10, y = 1000000000 * (long double)1000000000 + 10;
        for (int i = 0; i < n; i++)
        {
            x = max(x, mas[i].first - m * mas[i].second);
            y = min(y, mas[i].first + m * mas[i].second);
        }
        //cout << (double)m << " " << (double)x << " " << (double)y << endl;
        if (y > x)
            ri = m;
        else
            le = m;
    }
    cout.precision(20);
    cout << (double)ri << endl;
    return 0;
}