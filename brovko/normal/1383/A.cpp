#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int t, n, Min[20];
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
        int F = 0;

        for(int i = 0; i < 20; i++)
        {
            int f = 0;
            int Min = 1e9;

            for(int j = 0; j < n; j++)
            {
                if(a[j] - 'a' == i && b[j] > a[j])
                {
                    f = 1;

                    Min = min(Min, (int)b[j] - 'a');
                }

                if(b[j] < a[j])
                    F = 1;
            }

            if(f)
            {
                ans++;

                for(int j = 0; j < n; j++)
                    if(a[j] - 'a' == i && b[j] > a[j])
                        a[j] = Min + 'a';
            }
        }

        if(F)
            cout << "-1\n";
        else cout << ans << "\n";
    }
}