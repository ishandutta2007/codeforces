#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, x;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> x >> s;

        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            int c = 0;

            while(i < n && s[i] == '*')
            {
                c++;
                i++;
            }

            if(c > 0)
                v.pb(c);
        }

        int cnt = v.size();
        int a[cnt];

        x--;

        for(int i = cnt - 1; i >= 0; i--)
        {
            a[i] = x % (v[i] * k + 1);
            x /= (v[i] * k + 1);
        }

        int z = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
                cout << 'a';
            else
            {
                while(i < n && s[i] == '*')
                    i++;

                i--;

                for(int j = 0; j < a[z]; j++)
                    cout << 'b';

                z++;
            }
        }

        cout << "\n";
    }
}