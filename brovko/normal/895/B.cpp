#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, k, a[100005];

int f(int x, int y, int k)
{
    if(x > y)
        return -1;

    int L = (x + k - 1) / k;
    int R = y / k;
    return R - L + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> k;

    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);

    int L = 0;
    int R = 0;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        while(L < n && f(a[i], a[L], x) < k)
            L++;
        while(R < n && f(a[i], a[R], x) <= k)
            R++;

        ans += R - L;
        //cout << L << ' ' << R << endl;
    }

    cout << ans;
}