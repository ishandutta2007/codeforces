#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int k = 0;
    for (; k < n; k++)
        if (arr[k] == 1)
            break;
    int l = k, r = k;
    for (int x = 1; x <= n; x++)
    {
        while (l > 0 && arr[l-1] <= x)
            l--;
        while (r < n-1 && arr[r+1] <= x)
            r++;
        printf("%i", (r-l+1) == x);
    }
    printf("\n");
    return 0;
}

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
        solve();
}