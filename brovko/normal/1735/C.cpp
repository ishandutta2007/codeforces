#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector <int> p(26, -1), r(26, -1);

        for(auto x:s)
        {
            if(p[x - 'a'] != -1)
                cout << (char)('a' + p[x - 'a']);
            else
            {
                for(int i = 0; i < 26; i++)
                {
                    if(x - 'a' == i || r[i] != -1)
                        continue;

                    p[x - 'a'] = i;

                    int cur = i, k = 0;

                    while(cur != x - 'a' && cur != -1)
                    {
                        cur = p[cur], k++;
                    }

                    if(cur != -1 && k != 25)
                        continue;

                    r[i] = x - 'a';
                    cout << (char)('a' + i);
                    break;
                }
            }
        }

        cout << "\n";
    }
}