#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    deque<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int ans = 1, prev = 0;
    for (int x = 1; x < arr.size(); x++)
    {
        if (arr[x] > arr[x-1] * 2)
            ans = max(ans, x - prev), prev = x;
    }
    ans = max(ans, n - prev);
    printf("%i\n", ans);
}