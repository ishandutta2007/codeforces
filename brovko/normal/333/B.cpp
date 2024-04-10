#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> ux(n + 1), uy(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        ux[x]++;
        uy[y]++;
    }

    int ans = 0;

    for(int i = 2; i <= (n + 1) / 2; i++)
    {
        int k = (ux[i] == 0) + (uy[i] == 0) + (ux[n + 1 - i] == 0) + (uy[n + 1 - i] == 0);

        ans += min(k, (n % 2 && i == (n + 1) / 2 ? 1 : 4));
    }

    cout << ans;
}