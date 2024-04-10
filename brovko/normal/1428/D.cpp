#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[100005], b[100005], used[100005], u[100005], z;
vector <pair <int, int> > v;

void f(int i)
{
    if(u[i])
        return;

    u[i] = 1;

    if(a[i] == 1)
    {
        v.push_back({i + 1, z + 1});
        z++;
    }
    else if(a[i] == 2)
    {
        v.push_back({i + 1, z + 1});
        f(b[i]);
    }
    else if(a[i] == 3)
    {
        v.push_back({i + 1, z + 1});
        v.push_back({b[i] + 1, z + 1});
        z++;
        f(b[i]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = n, y = n, k23 = 0, k1 = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == 3 && k23 > 0)
        {
            x--;

            while(a[x] != 2 && a[x] != 3 || used[x] == 1)
                x--;

            used[x] = 1;
            b[i] = x;
            k23--;
        }
        else if(a[i] > 1 && k1 > 0)
        {
            y--;

            while(a[y] != 1 || used[y] == 1)
                y--;

            used[y] = 1;
            b[i] = y;
            k1--;
        }
        else if(a[i] > 1)
        {
            cout << -1;
            return 0;
        }

        if(a[i] == 2 || a[i] == 3)
            k23++;

        if(a[i] == 1)
            k1++;
    }

    for(int i = 0; i < n; i++)
        f(i);

    cout << v.size() << "\n";

    for(auto to:v)
        cout << to.second << ' ' << to.first << "\n";
}