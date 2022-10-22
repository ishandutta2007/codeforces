#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;
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

        int x = 0, k = 0, b = (s[0] == '(' ? 1 : -1);

        for(int i = 1; i < n; i++)
        {
            b += (s[i] == '(' ? 1 : -1);

            if(b == 0 && s[x] == '(')
            {
                k++;
                x = i + 1;
            }
            else
            if(s[i] == s[x] && i != x)
            {
                k++;
                x = i + 1;
                b = 0;
            }
        }

        cout << k << ' ' << n - x << "\n";
    }
}