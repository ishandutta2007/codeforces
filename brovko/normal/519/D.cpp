#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a[26], n, ps[100005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 26; i++)
        cin >> a[i];

    cin >> s;
    n = s.size();

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[s[i] - 'a'];

    map <pair <int, int>, int> m;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += m[{ps[i], s[i]}];
        m[{ps[i + 1], s[i]}]++;
    }

    cout << ans;
}