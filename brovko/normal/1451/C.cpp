#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, k, ca[128], cb[128];
string a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> a >> b;

        for(int i = 'a'; i <= 'z'; i++)
        {
            ca[i] = 0;
            cb[i] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            ca[a[i]]++;
            cb[b[i]]++;
        }

        int f = 1;

        int d = 0;

        for(int i = 'a'; i <= 'z'; i++)
        {
            d += ca[i] - cb[i];

            if(d < 0 || d % k != 0)
                f = 0;
        }

        if(f)
            cout << "Yes\n";
        else cout << "No\n";
    }
}