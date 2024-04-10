#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, a, ans, f[max_n], f1[max_n], kol[max_n];
pair <int, int> m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        f1[a] = 1;
        kol[a]++;
        if (m[a].second == 0 || i - m[a].first == m[a].second)
        {
            if (kol[a] == 2)
            {
                m[a].second = i - m[a].first;
            }
            m[a].first = i;
        }
        else
        {
            f[a] = 1;
        }
    }
    ans = 0;
    for (int i = 1; i <= 100000; i++)
        if (f1[i] == 1 && f[i] == 0) ans++;
    cout << ans << endl;
    for (int i = 1; i <= 100000; i++)
        if (f1[i] == 1 && f[i] == 0) cout << i << ' ' << m[i].second << endl;
    return 0;
}