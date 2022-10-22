#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int f = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] != 0)
            f = 1;
    }

    if(f == 0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    int x = 0;

    while(x < n)
    {
        while(x < n && a[x] == 0)
            x++;

        if(x < n)
            x++;

        while(x < n && a[x] == 0)
            x++;

        v.push_back(x);
    }

    int y = 1;

    cout << v.size() << "\n";

    for(auto to:v)
    {
        cout << y << ' ' << to << "\n";
        y = to + 1;
    }
}