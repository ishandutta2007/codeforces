#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, t[200005], s[200005], v[200005], x, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        if(t[i] == 1 || t[i] == 3)
            cin >> s[i];

        if(t[i] == 1)
            x = s[i];

        v[i] = x;
    }

    x = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        x = max(x, v[i]);

        if(t[i] == 5 || t[i] == 3 && s[i] >= x)
            x = 0;

        if(t[i] == 3 && s[i] < x)
            k++;
    }

    x = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(t[i] == 2)
            x = 1;

        if(t[i] == 4)
            x = 0;

        if(t[i] == 6 && x == 1)
            k++;
    }

    cout << k;
}