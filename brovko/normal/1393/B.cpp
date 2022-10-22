#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[100005], q, b[100005], k2, k4;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;

            if(b[a[i]] % 2 == 0)
                k2++;

            if(b[a[i]] % 4 == 0)
                k4++;
        }

    cin >> q;

    while(q--)
    {
        char c;
        int x;

        cin >> c >> x;

        if(c == '+')
        {
            b[x]++;

            if(b[x] % 2 == 0)
                k2++;

            if(b[x] % 4 == 0)
                k4++;
        }
        else
        {
            b[x]--;

            if(b[x] % 2 == 1)
                k2--;

            if(b[x] % 4 == 3)
                k4--;
        }

        if(k4 > 0 && k2 >= 4)
            cout << "YES\n";
        else cout << "NO\n";
    }
}