#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[105], b[1000005], used[1000005];
char c[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i] >> a[i];

        if(c[i] == '+')
            b[a[i]]++;
        else b[a[i]]--;

        if(b[a[i]] < 0)
        {
            used[a[i]] = 1;
        }
    }
    
    for(int i = 0; i < 1000005; i++)
        x += used[i];

    int ans = x;

    for(int i = 0; i < n; i++)
    {
        if(c[i] == '+')
            x++;
        else x--;

        ans = max(ans, x);
    }

    cout << ans;
}