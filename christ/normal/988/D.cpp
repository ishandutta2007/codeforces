#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    set<long long> arr;
    while (n--)
    {
        int a;
        scanf("%i", &a);
        arr.insert(a);
    }
    for (auto &x : arr)
    {
        for (long long d = 1; d < (1LL<<32); d *= 2)
            if (arr.count(x+d) && arr.count(x+2*d))
                return 0 * printf("3\n%lli %lli %lli\n", x, x+d, x+2*d);
    }
    for (auto &x : arr)
    {
        for (long long d = 1; d < (1LL<<32); d *= 2)
            if (arr.count(x+d))
                return 0 * printf("2\n%lli %lli\n", x, x+d);
    }
    printf("1\n%lli\n", *arr.begin());
}