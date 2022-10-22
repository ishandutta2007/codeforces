#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> cnt(200005);
    for (int x = 0; x < n; x++)
    {
        int a;
        scanf("%i", &a);
        cnt[a]++;
    }
    int l = 1, r = n;
    vector<int> ans;
    while (l <= r)
    {
        int m = l+r>>1;
        vector<int> cur;
        for (int x = 1; x < cnt.size(); x++)
            for (int y = 0; y < cnt[x] / m; y++)
                cur.push_back(x);
        if (cur.size() >= k)
            ans = cur, l = m+1;
        else
            r = m-1;
    }
    for (int x = 0; x < k; x++)
        printf("%i ", ans[x]);
}