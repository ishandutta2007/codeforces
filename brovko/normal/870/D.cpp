#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, p[5005], b[5005], ans[10005], P[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "? " << i << ' ' << 0 << endl;
        cin >> ans[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << "? " << 0 << ' ' << i << endl;
        cin >> ans[n + i];
    }

    int k = 0;

    for(b[0] = 0; b[0] < n; b[0]++)
    {
        for(int i = 0; i < n; i++)
            p[i] = (b[0] ^ ans[i]);

        for(int i = 0; i < n; i++)
            b[i] = (p[0] ^ ans[n + i]);

        int F = 1;

        for(int i = 0; i < n; i++)
            if(p[b[i]] != i || p[i] >= n || b[i] >= n)
                F = 0;

        if(F == 0)
            continue;

        k++;

        for(int i = 0; i < n; i++)
            P[i] = p[i];
    }

    cout << "!\n" << k << "\n";

    for(int i = 0; i < n; i++)
        cout << P[i] << ' ';
}