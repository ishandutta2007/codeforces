#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, b[600005], a[600005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> b[i];

    reverse(b, b + n);

    int S = 0, V = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        V += a[i];
        S += V - a[i];

        int d = b[i] - S;

//        cout << d << ' ';

        int c;

        if(i + k > n)
            k = n - i;

        c = max(0ll, (d + k - 1) / k);

//        cout << c << endl;

        ans += c;

        S += c * k;
        V -= c;
        a[i + k] += c;
    }

    cout << ans;
}