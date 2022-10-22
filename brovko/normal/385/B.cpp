#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    vector <int> v;

    for(int i = 3; i < s.size(); i++)
        if(s.substr(i - 3, 4) == "bear")
            v.pb(i);

    v.pb(s.size());

    int ans = 0;

    for(int i = 0; i + 1 < v.size(); i++)
        ans += (v[i + 1] - v[i]) * (v[i] - 2);

    cout << ans;
}