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
        vector<pair<int,int>> arr(n);
        for (auto &x : arr)
            scanf("%i%i", &x.first, &x.second);
        sort(arr.begin(), arr.end());
        for (int x = 1; x < n; x++)
            if (!(arr[x].second >= arr[x-1].second))
            {
                printf("NO\n");
                goto NXT;
            }
        {
            printf("YES\n");
            int px = 0, py = 0;
            for (auto &x : arr)
            {
                for (; px < x.first; px++)
                    printf("R");
                for (; py < x.second; py++)
                    printf("U");
            }
            printf("\n");
        }
NXT:;
    }
}