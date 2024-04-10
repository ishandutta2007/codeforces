#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a, b, k;
string s;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k >> s;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
            x = 0;
        else x++;

        if(x == b)
        {
            x = 0;
            v.push_back(i);
        }
    }

    cout << (int)v.size() - a + 1 << "\n";

    for(int i = 0; i < (int)v.size() - a + 1; i++)
        cout << v[i] + 1 << ' ';
}