#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
            k++;
        if(t[i] == '1')
            k--;
    }

    if(k != 0)
    {
        cout << -1;
        return 0;
    }

    int ps[n + 1];

    ps[0] = 0;

    for(int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i];

        if(s[i] == '1' && t[i] == '0')
            ps[i + 1]++;

        if(s[i] == '0' && t[i] == '1')
            ps[i + 1]--;
    }

    int Max = 0;
    int Min = 0;

    int ans = 0;

    for(int i = 0; i <= n; i++)
    {
        Max = max(Max, ps[i]);
        Min = min(Min, ps[i]);

        ans = max(ans, abs(ps[i] - Max));
        ans = max(ans, abs(ps[i] - Min));
    }

    cout << ans;
}