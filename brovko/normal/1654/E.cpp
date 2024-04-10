#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int Q = 100;
const int N = 100005;

int kd[2 * N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(int d = -Q; d <= Q; d++)
    {
        unordered_map <li, int> m;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, ++m[a[i] - i * 1ll * d]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j <= min(n - 1, i + N / Q); j++)
            if((a[j] - a[i]) % (j - i) == 0)
                ans = max(ans, ++kd[(a[j] - a[i]) / (j - i) + N] + 1);

        for(int j = i + 1; j <= min(n - 1, i + N / Q); j++)
            kd[(a[j] - a[i]) / (j - i) + N] = 0;
    }

    cout << n - ans;
}