#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(b[i] == '1')
            {
                if(i > 0 && a[i - 1] == '1')
                {
                    a[i - 1] = '0';
                    ans++;
                }
                else if(a[i] == '0')
                    ans++;

                else if(i < n - 1 && a[i + 1] == '1')
                {
                    a[i + 1] = '0';
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }
}