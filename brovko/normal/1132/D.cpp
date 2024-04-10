#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, b[200005];
long long a[200005], c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    long long L = -1, R = 1e13;

    while(R - L > 1)
    {
        long long M = (L + R) / 2;

        priority_queue <pair <int, int> > q;

        for(int i = 0; i < n; i++)
        {
            c[i] = a[i];
            q.push({max(-(c[i] / b[i]), (long long)-k), i});
        }

        int f = 1;

        for(int i = 0; i < k; i++)
        {
            int x = q.top().y;

            if(c[x] / b[x] < i)
                f = 0;

            q.pop();

            c[x] += M;

            if(c[x] > 1e18)
                c[x] = 1e18;

            q.push({max(-(c[x] / b[x]), (long long)-k), x});
        }

        if(f)
            R = M;
        else L = M;
    }

    if(R == 1e13)
        cout << -1;
    else cout << R;
}