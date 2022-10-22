#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, s, a[100005], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int L = 0;
    int R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        vector <int> v;

        for(int i = 0; i < n; i++)
            v.push_back(a[i] + (i + 1) * M);

        sort(v.begin(), v.end());
        int x = 0;

        for(int i = 0; i < M; i++)
            x += v[i];

        if(s >= x)
            {
                L = M;
                ans = x;
            }
        else R = M;
    }

    cout << L << ' ' << ans;
}