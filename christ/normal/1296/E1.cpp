#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<char> arr(n);
    for (auto &x : arr)
        scanf(" %c", &x);
    vector<pair<bool,bool>> col(26);
    vector<int> ans(n);
    for (int x = 0; x < n; x++)
    {
        int chr = arr[x] - 'a';
        bool has0 = false, has1 = false;
        for (int y = chr + 1; y < 26; y++)
            has0 |= col[y].first, has1 |= col[y].second;
        if (has0 && has1)
            return 0 * printf("NO\n");
        if (has0)
            col[chr].second = 1, ans[x] = 1;
        else
            col[chr].first = 1, ans[x] = 0;
    }
    printf("YES\n");
    for (auto &x : ans)
        printf("%i", x);
    printf("\n");
}