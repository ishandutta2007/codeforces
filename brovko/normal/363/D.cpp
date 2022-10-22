#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a, b[100005], p[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a;

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int j = 0; j < m; j++)
        cin >> p[j];

    sort(p, p + m);
    sort(b, b + n);

    int L = 0, R = min(m, n) + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int d = n - M;
        int s = 0;

        for(int i = 0; i < M; i++)
        {
            s += max(0ll, p[i] - b[i + d]);
        }

        if(s <= a)
            L = M;
        else R = M;
    }

    int s = 0;

    for(int i = 0; i < L; i++)
        s += p[i];

    cout << L << ' ' << max(0ll, s - a);
}