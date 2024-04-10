#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    int mi = 1;
    arr[0] = 1;
    for (int x = 1; x < n; x++)
    {
        int a;
        scanf("%i", &a);
        arr[x] = arr[x-1] + a;
        mi = min(mi, arr[x]);
    }
    mi--;
    for (auto &x : arr)
        x -= mi;
    auto b = arr;
    sort(b.begin(), b.end());
    for (int x = 0; x < b.size(); x++)
        if (b[x] != x+1)
            return 0 * printf("-1\n");
    for (auto &x : arr)
        printf("%i ", x);
    printf("\n");
}