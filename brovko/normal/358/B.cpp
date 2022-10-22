#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
string s[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    string t = "<3";

    for(int i = 0; i < n; i++)
        t += s[i] + "<3";

    string w;
    cin >> w;

    int x = 0;

    for(int i = 0; i < t.size(); i++)
    {
        while(x < w.size() && w[x] != t[i])
            x++;

        if(x >= w.size())
        {
            cout << "no";
            return 0;
        }

        x++;
    }

    cout << "yes";
}