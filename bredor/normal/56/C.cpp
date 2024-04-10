//  228

#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
string s;
int g = 0, ret = 0;
map<string, int> m;
void solve()
{
    string a;
    while (s[g] >= 'A' && s[g] <= 'Z')
    {
        a += s[g++];
    }
    ret += m[a];
    m[a]++;
    while (s[g] != '.')
    {
        g++;
        solve();
    }
    g++;
    m[a]--;
}

void hehe()
{
    cin >> s;
    solve();
    cout << ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        hehe();
    }

    return 0;
}