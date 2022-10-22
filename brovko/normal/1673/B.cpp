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
        string s;
        cin >> s;

        vector <int> k(128);

        int n = s.size();

        int i = 0;

        while(i < n && k[s[i]] == 0)
        {
            k[s[i]]++;
            i++;
        }

        int F = 1;

        for(int j = i; j < n; j++)
            if(s[j] != s[j - i])
                F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}