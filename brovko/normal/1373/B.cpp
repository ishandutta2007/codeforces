#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

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

        int n = s.size();

        int k1 = 0, k0 = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                k0++;
            else k1++;
        }

        if(min(k0, k1) % 2 == 0)
            cout << "NET\n";
        else cout << "DA\n";
    }
}