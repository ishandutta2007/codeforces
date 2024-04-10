#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
vector <string> v[1000005];
int n, x, Max;

void dfs(int d)
{
    Max = max(Max, d);
    int y = x;

    while(s[x] != ',')
        x++;

    v[d].push_back(s.substr(y, x - y));

    x++;

    int p = 0;

    while(s[x] != ',')
    {
        p = p * 10 + s[x] - '0';
        x++;
    }

    x++;

    while(p--)
        dfs(d + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    s += ",";

    n = s.size();

    while(x < n)
        dfs(1);

    cout << Max << "\n";

    for(int i = 1; i <= Max; i++)
        {
            for(auto to:v[i])
            {
                cout << to << ' ';
            }

            cout << "\n";
        }
}