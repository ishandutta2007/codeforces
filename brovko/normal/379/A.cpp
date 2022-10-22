#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    int c = 0;
    int ans = 0;

    while(a > 0)
    {
        a--;
        ans++;
        c++;

        if(c == b)
        {
            c = 0;
            a++;
        }
    }

    cout << ans;
}