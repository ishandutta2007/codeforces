#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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
        vector <int> v;

        for(int i = 1; i <= 12; i++)
            if(12 % i == 0)
            {
                int j = 12 / i;
                int k[j];

                for(int z = 0; z < j; z++)
                    k[z] = 1;

                for(int z = 0; z < s.size(); z++)
                    if(s[z] == 'O')
                        k[z % j] = 0;

                int s = 0;

                for(int z = 0; z < j; z++)
                    s += k[z];

                if(s)
                    v.pb(i);
            }

        cout << v.size() << ' ';

        for(auto x:v)
            cout << x << 'x' << 12 / x << ' ';

        cout << "\n";
    }
}