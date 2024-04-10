#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    scanf("%i%i%i", &n, &x, &y);
    vector<int> arr(n);
    int ans = 0;
    for (auto &a : arr)
        scanf("%i", &a);
    if (x > y)
        return 0 * printf("%i\n", n);
    for (auto &a : arr)
    {
        if (a <= x)
            ans++;
    }
    printf("%i\n", ans+1>>1);
}