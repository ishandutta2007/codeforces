#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, m;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> s;

        string x;

        for(int i = 0; i < min(n, m); i++)
        {
            x = s;

            for(int j = 0; j < n; j++)
            {
                int f = 0;

                if(j > 0 && s[j - 1] == '1')
                    f++;

                if(j < n - 1 && s[j + 1] == '1')
                    f++;

                if(f == 1)
                    x[j] = '1';
            }

            s = x;
        }

        cout << s << "\n";
    }
}