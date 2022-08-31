#include <iostream>

using namespace std;

int a[100005];

int main()
{
    int n, h, k;
    cin >> n >> h >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long ans = 0, cur = 0, free = h, temp;

    for (int i = 0; i < n; )
    {
        while (a[i] <= free and i < n)
        {
            cur += a[i];
            free -= a[i];
            ++i;
        }

        if (i >= n)
            temp = cur;

        else
            temp = a[i] - free;

        if (temp % k == 0)
            temp /= k;

        else
            temp = (temp / k) + 1;

        ans += temp;

        cur -= temp * k;
        cur = max(cur, 0ll);

        free = h - cur;
    }

    cout << ans;
}