#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int ans = 0;

    for(int i = 1; i < n; i++)
        if(s[i] == s[i - 1])
            ans++;

    cout << ans;
}