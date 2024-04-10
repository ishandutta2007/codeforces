#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005], suf[200005];

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

        for(int i = 0; i <= n; i++)
            b[i] = 0;

        int mex = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            b[a[i]]++;

            while(b[mex])
                mex++;

            suf[i] = mex;
        }

        for(int i = 0; i < n; i++)
            b[a[i]] = 0;

        int r = 0;
        mex = 0;

        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            b[a[i]]++;

            while(b[mex])
                mex++;

            if(mex == suf[r])
            {
                for(int j = r; j <= i; j++)
                    b[a[j]] = 0;

                r = i + 1;
                v.pb(mex);

                mex = 0;
            }
        }

        cout << v.size() << "\n";

        for(auto x:v)
            cout << x << ' ';

        cout << "\n";
    }
}