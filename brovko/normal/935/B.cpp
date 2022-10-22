#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x[100005], y[100005], ans;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++)
    {
        x[i + 1] = x[i];
        y[i + 1] = y[i];
        if(s[i]=='U')
            y[i + 1]++;
        else x[i + 1]++;

        if(i > 0)
        {
            if(x[i - 1] > y[i - 1] && x[i + 1] < y[i + 1])
                ans++;
            if(x[i - 1] < y[i - 1] && x[i + 1] > y[i + 1])
                ans++;
        }
    }

    cout << ans;
}