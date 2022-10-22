#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, k, a[100005], b[100005];

int f(int x, int k)
{
    return x % k * (x / k + 1) * (x / k + 1) + (k - x % k) * (x / k) * (x / k);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    priority_queue <pair <int, int> > q;

    for(int i = 0; i < n; i++)
    {
        b[i] = 1;
        q.push({f(a[i], 1) - f(a[i], 2), i});
        ans += a[i] * a[i];
    }

    for(int i = 0; i < k - n; i++)
    {
        int x = q.top().second;
        ans -= q.top().first;
        q.pop();

        b[x]++;
        q.push({f(a[x], b[x]) - f(a[x], b[x] + 1), x});
    }

    cout << ans;
}