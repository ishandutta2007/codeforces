#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

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
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        int F = 1;
        int j = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                if(s[i] == 'a' && t[i] == 'c' || s[i] > t[i])
                    F = 0;
                else
                {
                    j = max(j, i);

                    while(j < n && s[j] == s[i])
                    {
                        j++;
                    }

                    if(j == n || s[j] != t[i])
                        F = 0;
                    else swap(s[i], s[j]);
                }
            }
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}