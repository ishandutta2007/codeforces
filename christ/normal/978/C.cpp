#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<long long> cnt(n);
    for (int x = 0; x < n; x++)
    {
        long long a;
        scanf("%lli", &a);
        cnt[x] = a;
        if (x)
            cnt[x] += cnt[x-1];
    }
    while (m--)
    {
        long long b;
        scanf("%lli", &b);
        auto it = lower_bound(cnt.begin(), cnt.end(), b);
        long long dorm = it - cnt.begin();
        long long v = (it == cnt.begin() ? 0 : *(--it));
        printf("%lli %lli\n", dorm + 1, b - v);
    }
}