#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, p;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    cin >> s;

    int x = n - 1;
    bool F = 1;

    while(F)
    {
        s[x]++;

        while(x >= 1 && s[x] == s[x - 1] || x >= 2 && s[x] == s[x - 2])
            s[x]++;

        if(s[x] - 'a' + 1 > p)
            x--;
        else F = 0;

        if(x < 0)
        {
            cout << "NO";
            return 0;
        }
    }

    for(int i = x + 1; i < n; i++)
    {
        s[i] = 'a';

        while(i >= 1 && s[i] == s[i - 1] || i >= 2 && s[i] == s[i - 2])
            s[i]++;

        if(s[i] - 'a' + 1 > p)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << s;
}