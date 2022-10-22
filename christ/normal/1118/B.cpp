#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int tot[2] = {0, 0};
    for (int x = 0; x < n; x++)
        tot[x&1] += arr[x];
    int sum[2] = {0, 0};
    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        tot[x&1] -= arr[x];
        if (sum[0] + tot[1] == sum[1] + tot[0])
            ans++;
        sum[x&1] += arr[x];
    }
    printf("%i\n", ans);
}