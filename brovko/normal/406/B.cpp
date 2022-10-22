#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[500005], used[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        used[a[i]] = 1;
    }

    int k = 0;

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        if(used[1000001 - a[i]])
            k++;
        else
        {
            v.pb(1000001 - a[i]);
            used[v.back()] = 1;
        }
    }

    int x = 1;

    while(k > 0)
    {
        if(used[x])
            x++;
        else
        {
            k -= 2;
            v.pb(x);
            v.pb(1000001 - x);
            x++;
        }
    }

    cout << v.size() << "\n";

    for(auto x:v)
        cout << x << ' ';
}