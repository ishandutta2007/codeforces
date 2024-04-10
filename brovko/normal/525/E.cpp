#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, s, a[30], fact[100];
map <int, int> L[30], R[30];

void rec(int l, int r, int cnt, int sum)
{
    if(l == r)
    {
        if(r == n)
            R[cnt][sum]++;
        else L[cnt][sum]++;

        return;
    }

    rec(l + 1, r, cnt, sum);
    rec(l + 1, r, cnt, sum + a[l]);

    if(a[l] <= 18)
        rec(l + 1, r, cnt + 1, sum + fact[a[l]]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    fact[0] = 1;

    for(int i = 1; i < 100; i++)
        fact[i] = fact[i - 1] * i;

    rec(0, n / 2, 0, 0);
    rec(n / 2, n, 0, 0);

    int ans = 0;

    for(int c = 0; c <= k; c++)
        for(int c2 = 0; c2 <= k - c; c2++)
        {
            for(auto x:L[c])
                ans += x.y * R[c2][s - x.x];
        }

    cout << ans;
}