#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[105], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < k; i++)
        cin >> b[i];

    sort(b, b + k);

    int x = k - 1;

    for(int i = 0; i < n; i++)
        if(a[i] == 0)
        {
            a[i] = b[x];
            x--;
        }

    for(int i = 1; i < n; i++)
        if(a[i] <= a[i - 1])
        {
            cout << "Yes";
            return 0;
        }

    cout << "No";
}