#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n;
string a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        int k0 = 0, k1 = 0, ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == '0' || b[i] == '0')
                k0++;

            if(a[i] == '1' || b[i] == '1')
                k1++;

            if(k0 == 0 && k1 == 1)
            {
                while(i < n && a[i] == '1' && b[i] == '1')
                    i++;

                if(i < n)
                    ans += 2;

                k0 = 0;
                k1 = 0;
            }
            else if(k0 == 1 && k1 == 0)
            {
                if(i + 1 < n && a[i + 1] == '1' && b[i + 1] == '1')
                {
                    i++;
                    ans += 2;
                    k0 = 0;
                    k1 = 0;
                }
            }

            if(k0 + k1 > 0)
            {
                if(k0 > 0 && k1 > 0)
                    ans += 2;

                else if(k0 > 0)
                    ans++;

                k0 = 0;
                k1 = 0;
            }
        }

        cout << ans << "\n";
    }
}