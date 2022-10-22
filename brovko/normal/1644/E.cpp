#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, mx[200005], my[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        int x = 1, y = 1;

        mx[1] = 1;
        my[1] = 1;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'D')
                x++;
            else y++;

            mx[x] = y;
            my[y] = x;
        }

        if(x == 1 || y == 1)
        {
            cout << n << "\n";
            continue;
        }

        int ans = n * n;

        for(int i = 1; i <= x; i++)
        {
            if(mx[i] == 1)
                ans -= n - 1;
            else ans -= y - mx[i];
        }

        for(int i = 1; i <= y; i++)
        {
            if(my[i] == 1)
                ans -= n - 1;
            else ans -= x - my[i];
        }

        cout << ans << "\n";
    }
}