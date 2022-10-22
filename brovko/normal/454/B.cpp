#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

    vector <int> v;

    for(int i = 0; i < n; i++)
        if(a[i] > a[(i + 1) % n])
            v.pb(i);

    if(v.size() >= 2)
        cout << -1;
    else if(v.size() == 0)
        cout << 0;
    else cout << n - 1 - v[0];
}