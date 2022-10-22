#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    int a[n];
    int cnt = 0, s = 0;

    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        s += a[i];

        if(a[i] < y)
            cnt++;
    }

    int i = k;

    while(i < n && cnt < n / 2)
    {
        a[i] = 1;
        s++;
        cnt++;
        i++;
    }

    for(; i < n; i++)
    {
        a[i] = y;
        s += a[i];
    }

    if(cnt > n / 2 || s > x)
        cout << -1;
    else
    {
        for(int i = k; i < n; i++)
            cout << a[i] << ' ';
    }
}