#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[200005], l[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    l[0] = -1;

    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1])
            l[i] = l[i - 1];
        else l[i] = i - 1;
    }

    while(m--)
    {
        int L, R, X;
        cin >> L >> R >> X;

        L--;
        R--;

        if(a[R] != X)
            cout << R + 1 << "\n";

        else if(l[R] >= L)
            cout << l[R] + 1 << "\n";

        else cout << "-1\n";
    }
}