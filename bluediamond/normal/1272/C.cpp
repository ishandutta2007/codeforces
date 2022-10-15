#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n, k;
    cin >> n >> k >> s;
    map<char, bool> good;
    for (int i = 1; i <= k; i++)
    {
        string t;
        cin >> t;
        good[t[0]] = 1;
    }
    ll ans = 0;
    int len = 0;
    for (auto &c : s)
    {
        if (good[c])
        {
            len++;
        }
        else
        {
            len = 0;
        }
        ans += len;
    }
    cout << ans << "\n";
}