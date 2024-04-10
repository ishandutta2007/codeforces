#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[1005], b[1005], used[1005];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            v.push_back(i);
        else used[a[i]]++;

    if(v.size() == 1)
    {
        int x = 1;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == b[i])
            {
                cout << a[i] << ' ';
            }
            else
            {
                while(used[x])
                    x++;
                used[x] = 1;
                cout << x << ' ';
            }
        }

        return 0;
    }

    if(used[a[v[0]]] == 0 && used[b[v[1]]] == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == v[1])
                cout << b[i] << ' ';
            else cout << a[i] << ' ';
        }
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == v[0])
            cout << b[i] << ' ';
        else cout << a[i] << ' ';
    }
}