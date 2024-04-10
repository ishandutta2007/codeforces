#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;
        s += "1";

        int k = 0, x = 0;

        for(auto to:s)
        {
            if(to == '0')
                x++;
            else
            {
                if(x > 0)
                    k++;

                x = 0;
            }
        }

        cout << min(2ll, k) << "\n";
    }
}