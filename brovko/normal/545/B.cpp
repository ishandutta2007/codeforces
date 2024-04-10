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

    string s, t;
    cin >> s >> t;

    int k = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != t[i])
        {
            if(k)
                s[i] = t[i];

            k = 1 - k;
        }
    }

    if(k)
        cout << "impossible";
    else cout << s;
}