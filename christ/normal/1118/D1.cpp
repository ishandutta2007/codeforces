#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<long long> arr(n);
    for (auto &x : arr)
        scanf("%lli", &x);
    sort(arr.rbegin(), arr.rend());
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = l+r>>1;
        long long pag = 0;
        for (int x = 0; x < n; x++)
            pag += max(0LL, arr[x] - x / mid);
        if (pag >= m) // do in less days
            r = mid-1;
        else
            l = mid+1;
    }
    printf("%i\n", l > n ? -1 : l);
}