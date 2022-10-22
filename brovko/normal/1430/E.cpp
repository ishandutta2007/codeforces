#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, t[200005], x[26];
string s;
vector <int> v[26];

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= n; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++)
        v[s[i] - 'a'].pb(i);

    for(int i = 0; i < n; i++)
        inc(i, 1);

    int ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        inc(v[s[i] - 'a'][x[s[i] - 'a']], -1);
        ans += sum(v[s[i] - 'a'][x[s[i] - 'a']]);
        x[s[i] - 'a']++;
    }

    cout << ans;
}