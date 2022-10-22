#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long w;
    scanf("%i%lli", &n, &w);
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    long long cur = 0, mi = 0, ma = 0;
    for (auto &x : arr)
    {
        cur += x;
        mi = min(mi, cur);
        ma = max(ma, cur);
    }
    printf("%lli\n", max(0LL, (w - ma) + mi + 1));
}