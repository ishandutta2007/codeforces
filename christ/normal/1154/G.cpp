#include <bits/stdc++.h>

using namespace std;

const int MAXA = 10000005, MAXN = 1000005;

vector<int> cnt(MAXA), a(MAXN);

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a[x]);
        cnt[a[x]]++;
    }
    long long ans = LLONG_MAX;
    int x1, x2;
    for (int x = 1; x <= MAXA; x++)
    {
        if (cnt[x] >= 2)
        {
            if (ans > x)
            {
                ans = x;
                x1 = x, x2 = x;
            }
        }
        else
        {
            int y1 = 0, y2 = x;
            while (y2 <= MAXA)
            {
                if (cnt[y2])
                    break;
                y2 += x;
            }
            if (y2 <= MAXA)
            {
                y1 = y2;
                y2 += x;
                while (y2 <= MAXA)
                {
                    if (cnt[y2])
                        break;
                    y2 += x;
                }
                if (y2 <= MAXA)
                {
                    long long val = (long long)y2 / x * y1;
                    if (ans > val)
                    {
                        ans = val;
                        x1 = y1, x2 = y2;
                    }
                }
            }
        }
    }
    int x = 0;
    while (a[x] != x1)
        x++;
    int ans1 = x + 1, ans2;
    if (x1 != x2)
        x = 0;
    else
        x++;
    while (a[x] != x2)
        x++;
    ans2 = x + 1;
    if (ans2 < ans1)
        swap(ans2, ans1);
    printf("%i %i\n", ans1, ans2);
}