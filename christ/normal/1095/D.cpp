#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<pair<int,int>> arr(n+1);
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &arr[x].first, &arr[x].second);
    vector<int> ans(n+1);
    for (int x = 1, c = 0; c < n; c++, x = ans[x])
    {
        printf("%i ", x);
        if (!(c != n-1 && arr[x].first == 1) && (arr[arr[x].first].first == arr[x].second || arr[arr[x].first].second == arr[x].second))
            ans[x] = arr[x].first;
        else
            ans[x] = arr[x].second;
    }
}