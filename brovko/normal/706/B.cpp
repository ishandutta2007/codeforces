#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int q;
    cin >> q;

    while(q--)
    {
        int x;
        cin >> x;

        int L = -1;
        int R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(a[M] <= x)
                L = M;
            else R = M;
        }

        cout << L + 1 << "\n";
    }
}