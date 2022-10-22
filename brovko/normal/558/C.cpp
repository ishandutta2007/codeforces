#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define vi vector <int>

using namespace std;

int n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[i] = a[i];

    int ans = 1e9;

    int x = 0;

    int Min = a[0];

    while(Min > 0)
    {
        for(int i = 0; i < n; i++)
            a[i] = b[i];

        int y = 0;

        int F = 1;

        for(int i = 0; i < n; i++)
        {
            while(a[i] > 0 && (a[i] % Min > 0 || (a[i] / Min & a[i] / Min - 1) > 0))
            {
                a[i] /= 2;
                y++;
            }

            if(a[i] == 0)
            {
                F = 0;
                break;
            }
        }

        if(F == 0)
        {
            Min /= 2;
            x++;
            continue;
        }

        sort(a, a + n);

//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//
//        cout << endl;

        for(int i = 0; i < n; i++)
        {
            while(a[i] != a[n / 2])
            {
                if(a[i] < a[n / 2])
                    a[i] *= 2;
                else a[i] /= 2;

                y++;
            }
        }

        ans = min(ans, y);

        Min /= 2;
        x++;
    }

    cout << ans;
}