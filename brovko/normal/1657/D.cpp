#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, C, c[300005], d[300005], h[300005], m, D[300005], H[300005], Max[1000005], dh[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> C;

    for(int i = 0; i < n; i++)
        cin >> c[i] >> d[i] >> h[i];

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> D[i] >> H[i];

    for(int i = 0; i < n; i++)
        dh[c[i]] = max(dh[c[i]], d[i] * h[i]);

    for(int i = 1; i <= C; i++)
        for(int j = i; j <= C; j += i)
            Max[j] = max(Max[j], dh[i] * (j / i));

    for(int i = 2; i <= C; i++)
        Max[i] = max(Max[i], Max[i - 1]);

    for(int i = 0; i < m; i++)
    {
        int DH = D[i] * H[i];

        int L = 0, R = C + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(Max[M] > DH)
                R = M;
            else L = M;
        }

        if(R > C)
            cout << "-1 ";
        else cout << R << ' ';
    }
}