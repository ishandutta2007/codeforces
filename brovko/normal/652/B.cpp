#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int l = 0;
    int r = n - 1;

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            cout << a[l] << ' ';
            l++;
        }
        else
        {
            cout << a[r] << ' ';
            r--;
        }
    }
}