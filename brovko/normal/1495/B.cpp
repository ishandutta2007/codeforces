#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[100005], l[100005], r[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    l[0] = 1;

    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
            l[i] = l[i - 1] + 1;
        else l[i] = 1;
    }

    r[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] > a[i + 1])
            r[i] = r[i + 1] + 1;
        else r[i] = 1;
    }

    int Max = 0;

    for(int i = 0; i < n; i++)
        Max = max(Max, max(l[i], r[i]));

    int f = 0, x = 0;

    for(int i = 0; i < n; i++)
    {
        if(l[i] == Max)
        {
            f++;
            x = i;
        }
    }

    if(f != 1)
    {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(i != x && r[i] == Max)
        {
            cout << 0;
            return 0;
        }
    }

    if(l[x] == Max && r[x] == Max && Max % 2 != 0)
        cout << 1;
    else cout << 0;
}