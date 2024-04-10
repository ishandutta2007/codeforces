#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += min(abs(s[i] - t[i]), 10 - abs(s[i] - t[i]));
    }

    cout << ans;
}