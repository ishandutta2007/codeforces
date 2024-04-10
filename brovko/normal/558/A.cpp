#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define vi vector <int>

using namespace std;

int n, x[105], a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> a[i];

    vector <pair <int, int> > pos, neg;

    for(int i = 0; i < n; i++)
    {
        if(x[i] > 0)
            pos.pb({x[i], a[i]});
        else neg.pb({x[i], a[i]});
    }

    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());

    int P = pos.size(), N = neg.size();

    if(P > N + 1)
        P = N + 1;

    if(N > P + 1)
        N = P + 1;

    int ans = 0;

    for(int i = 0; i < P; i++)
        ans += pos[i].y;

    for(int i = 0; i < N; i++)
        ans += neg[i].y;

    cout << ans;
}