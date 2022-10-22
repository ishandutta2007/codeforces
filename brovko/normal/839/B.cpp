#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[10005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];

    int k2 = n * 2;
    int k4 = n;
    int k1 = 0;

    for(int i = 0; i < k; i++)
    {
        int c = min(k4, a[i] / 4);
        k4 -= c;
        a[i] -= 4 * c;

        c = min(k2, a[i] / 2);
        k2 -= c;
        a[i] -= 2 * c;

        if(k4 > 0 && a[i] == 3)
        {
            a[i] = 0;
            k4--;
        }

        if(k4 > 0 && a[i] == 1)
        {
            a[i] = 0;
            k4--;
            k2++;
        }

        if(k4 > 0 && a[i] == 2)
        {
            a[i] = 0;
            k4--;
            k1++;
        }

        c = min(a[i], k1);
        a[i] -= c;
        k1 -= c;

        c = min(a[i], k2);
        a[i] -= c;
        k2 -= c;

        if(a[i] > 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}