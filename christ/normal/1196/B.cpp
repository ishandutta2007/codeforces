#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n, k;
        scanf("%i%i", &n, &k);
        vector<int> arr(n);
        for (auto &x : arr)
            scanf("%i", &x);
        vector<int> ans;
        long long cur = 0;
        for (int x = 0; x < n; x++)
        {
            cur += arr[x];
            if ((cur&1) && ans.size() < k-1)
            {
                ans.push_back(x);
                cur = 0;
            }
        }
        if (cur&1)
        {
            ans.push_back(n-1);
            printf("YES\n");
            for (auto &x : ans)
                printf("%i ", x+1);
            printf("\n");
        }
        else
            printf("NO\n");
    }
}