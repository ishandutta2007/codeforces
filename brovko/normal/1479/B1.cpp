#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[100005];
vector <int> x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    x.push_back(0);
    y.push_back(0);

    for(int i = 0; i < n; i++)
    {
        if(x[x.size() - 1] == a[i])
            y.push_back(a[i]);

        else if(y[y.size() - 1] == a[i])
            x.push_back(a[i]);

        else if(x[x.size() - 1] == a[i + 1])
            x.push_back(a[i]);

        else y.push_back(a[i]);
    }

    int ans = 0;

    for(int i = 1; i < x.size(); i++)
        if(x[i] != x[i - 1])
            ans++;

    for(int i = 1; i < y.size(); i++)
        if(y[i] != y[i - 1])
            ans++;

    cout << ans;
}