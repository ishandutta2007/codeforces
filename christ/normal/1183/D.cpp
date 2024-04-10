#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        scanf("%i", &n);
        vector<int> cnt(n+1);
        for (int x = 0; x < n; x++)
        {
            int a;
            scanf("%i", &a);
            cnt[a]++;
        }
        vector<int> good;
        for (int x = 1; x <= n; x++)
            if (cnt[x])
                good.push_back(cnt[x]);
        sort(good.rbegin(), good.rend());
        int ans = good[0];
        int prev = good[0];
        for (int x = 1; x < good.size(); x++)
        {
            if (good[x] < prev)
                prev = good[x], ans += good[x];
            else if (prev > 0)
                prev--, ans += prev;
        }
        printf("%i\n", ans);
    }
}