#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<char> arr(n);
    for (auto &x : arr)
        scanf(" %c", &x);
    vector<set<int>> col(26);
    vector<int> ans(n);
    int t = 0;
    for (int x = 0; x < n; x++)
    {
        int chr = arr[x] - 'a';
        set<int> used;
        for (int y = chr + 1; y < 26; y++)
            for (auto &z : col[y])
                used.insert(z);
        int cc = 0;
        while (used.count(cc))
            ++cc;
        ans[x] = cc;
        t = max(t, cc);
        col[chr].insert(cc);
    }
    printf("%i\n", t+1);
    for (auto &x : ans)
        printf("%i ", x + 1);
    printf("\n");
}