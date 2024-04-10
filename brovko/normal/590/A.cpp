#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[500005], b[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    b[0] = 1;
    b[n - 1] = 1;

    for(int i = 1; i < n - 1; i++)
    {
        if(a[i] == a[i - 1] || a[i] == a[i + 1])
            b[i] = 1;
    }

    int ans = 0;

    for(int i = 0; i < n - 1; i++)
    {
        int j = i + 1;

        while(b[j] == 0)
            j++;

        ans = max(ans, (j - i) / 2);

        if(a[i] == a[j])
        {
            for(int z = i + 1; z < j; z++)
            {
                a[z] = a[i];
                b[z] = 1;
            }
        }
        else
        {
            for(int z = i + 1; z < j; z++)
            {
                if(z - i <= j - z)
                    a[z] = a[i];
                else a[z] = a[j];

                b[z] = 1;
            }
        }
    }

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}