#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mas[n + 1];
    fill(mas, mas + n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (mas[i] == 0)
        {
            for (int j = 2; j <= n / i; j++)
                mas[i * j] = 1;
        }
    }
    int le = n, ri = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (mas[i] == 0 && n % i == 0)
        {
            le = n - i + 1;
            break;
        }
    }
    int ans = n + 1;
    //cout << le << " " << ri << endl;
    for (int i = 2; i <= n; i++)
    {
        if (mas[i] == 0)
        {
            int x = i * ((le + i - 1) / i);
            if (x <= ri && i < x)
            {
                ans = min(ans, x - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}