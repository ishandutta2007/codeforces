#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back


using namespace std;

int t, n, a[100005], b[100005];

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

        for(int i = 1; i <= n; i++)
            b[i] = 0;

        int mex = 1, ans = 0;

        for(int i = 0; i < n; i++)
        {
            b[a[i]]++;

            while(b[mex])
                mex++;

            if(mex > i + 1)
                ans++;
        }

        cout << ans << "\n";
    }
}