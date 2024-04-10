#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        int k0 = 0, k1 = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                k0++;
            else k1++;
        }

        cout << min({k0, k1, (n - 1) / 2}) << "\n";
    }
}