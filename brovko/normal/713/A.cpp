#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, pow10[20];
map <int, int> m;

int f(int x)
{
    int ans = 0;
    int y = 0;

    while(x)
    {
        if(x % 2)
            ans += pow10[y];

        y++;
        x /= 10;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow10[0] = 1;

    for(int i = 1; i < 20; i++)
        pow10[i] = pow10[i - 1] * 10;

    cin >> t;

    while(t--)
    {
        char c;
        cin >> c;

        int x;
        cin >> x;

        if(c == '+')
            m[f(x)]++;

        if(c == '-')
            m[f(x)]--;

        if(c == '?')
            cout << m[x] << "\n";
    }
}