#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

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

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'U')
                cout << 'D';

            else if(s[i] == 'D')
                cout << 'U';

            else cout << s[i];
        }

        cout << "\n";
    }
}