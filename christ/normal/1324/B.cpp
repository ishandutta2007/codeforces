#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        vector<int> arr(n);
        vector<int> cnt(n+1);
        for (auto &x : arr)
            scanf("%i", &x), cnt[x]++;
        for (int x = 0; x < n; x++)
        {
            if (cnt[arr[x]] - (x < n-1 && arr[x] == arr[x+1]) - (x > 0 && arr[x] == arr[x-1]) >= 2)
            {
                printf("YES\n");
                goto NXT;
            }
        }
        printf("NO\n");
NXT:;
    }
}