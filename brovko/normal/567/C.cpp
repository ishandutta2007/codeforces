#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    map <int, int> l, r;

    for(int i = 0; i < n; i++)
        r[a[i]]++;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        r[a[i]]--;

        if(a[i] % k == 0)
            ans += l[a[i] / k] * r[a[i] * k];

        l[a[i]]++;
    }

    cout << ans;
}