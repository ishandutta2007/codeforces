#include <bits/stdc++.h>
#define int long long
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        string s;
        cin >> s;

        int n = s.size();

        int ka = 0, kb = 0;

        vector <int> aa, ab, ba, bb;

        for(int i = 0; i < n; i++)
        {
            int j = i;

            if(s[i] == 'A')
                ka++;
            else kb++;

            while(i < n - 1 && s[i] != s[i + 1])
            {
                i++;

                if(s[i] == 'A')
                    ka++;
                else kb++;
            }

            if(s[j] == 'A' && s[i] == 'A')
                aa.pb(i - j + 1);

            if(s[j] == 'A' && s[i] == 'B')
                ab.pb(i - j + 1);

            if(s[j] == 'B' && s[i] == 'A')
                ba.pb(i - j + 1);

            if(s[j] == 'B' && s[i] == 'B')
                bb.pb(i - j + 1);
        }

        sort(ab.begin(), ab.end());
        sort(ba.begin(), ba.end());

        bool F = (ka == a + c + d && kb == b + c + d);

        for(auto x:ab)
        {
            if(c >= x / 2)
                c -= x / 2;
            else
            {
                x -= 2 * c;
                c = 0;

                d -= (x - 1) / 2;
            }
        }

        for(auto x:ba)
        {
            if(d >= x / 2)
                d -= x / 2;
            else
            {
                x -= 2 * d;
                d = 0;

                c -= (x - 1) / 2;
            }
        }

        int k = 0;

        for(auto x:aa)
            k += x / 2;

        for(auto x:bb)
            k += x / 2;

        if(F && k >= c + d)
            cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
1
1 1 2 3
ABABABBAABAB

*/