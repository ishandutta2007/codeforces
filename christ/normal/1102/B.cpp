#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> arr(n);
    vector<int> col(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int cc = 0;
    for (int x = 1; x <= 5000; x++)
    {
        int c = 0;
        for (int y = 0; y < n; y++)
            if (arr[y] == x)
            {
                col[y] = cc++;
                cc %= k;
                c++;
            }
        if (c > k)
            return 0 * printf("NO\n");
    }
    for (int x = 0; x < k; x++)
    {
        for (auto &y : col)
            if (y == x)
                goto NXT;
        printf("NO\n");
        NXT:;
    }
    printf("YES\n");
    for (auto &x : col)
        printf("%i ", x+1);
}