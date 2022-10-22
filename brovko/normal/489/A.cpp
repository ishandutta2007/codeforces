#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << n << "\n";

    for(int i = 0; i < n; i++)
    {
        int Min = i;

        for(int j = i; j < n; j++)
            if(a[j] < a[Min])
                Min = j;

        cout << i << ' ' << Min << "\n";
        swap(a[i], a[Min]);
    }
}