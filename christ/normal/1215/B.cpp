#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> cnt(2);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int cur = 0;
    for (int x = 0; x < n; x++)
    {
        cur += arr[x] < 0;
        cnt[cur&1]++;
        // cnt == 0 -> positive
    }
    vector<long long> ans(2);
    cur = 0;
    int v = 0;
    for (int x = 0; x < n; x++)
    {
        cur += arr[x] < 0;
        for (int y = 0; y < 2; y++)
            ans[y] += cnt[y];
        cnt[cur&1^v]--;
        if (arr[x] < 0)
            swap(cnt[0], cnt[1]), v ^= 1;
    }
    printf("%lli %lli\n", ans[1], ans[0]);
}