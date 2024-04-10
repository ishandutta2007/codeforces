#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[200005], b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);

    for(int i = 0; i < m; i++)
    {
        int L = -1, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(a[M] <= b[i])
                L = M;
            else R = M;
        }

        cout << R << ' ';
    }
}