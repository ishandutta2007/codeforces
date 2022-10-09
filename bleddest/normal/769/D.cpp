#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> cnt(10051, 0);
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
    long long ans = 0;
    if (k == 0)
    {
        for(auto to : cnt)
            ans += to * 1ll * (to - 1) / 2;
    }
    else
    {
        for(int i = 0; i < 10051; i++)
            for(int j = 0; j < i; j++)
                if (__builtin_popcount(i ^ j) == k)
                    ans += cnt[i] * 1ll * cnt[j];
    }
    cout << ans << endl;
}