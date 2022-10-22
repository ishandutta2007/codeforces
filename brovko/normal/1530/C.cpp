#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int L = -1, R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            vector <int> A, B;

            for(int i = 0; i < n; i++)
            {
                A.pb(a[i]);
                B.pb(b[i]);
            }

            for(int i = 0; i < M; i++)
            {
                A.pb(100);
                B.pb(0);
            }

            sort(A.begin(), A.end());
            sort(B.begin(), B.end());

            int d = 0;

            for(int i = (n + M) / 4; i < n + M; i++)
                d += A[i] - B[i];

            if(d >= 0)
                R = M;
            else L = M;
        }

        cout << R << "\n";
    }
}