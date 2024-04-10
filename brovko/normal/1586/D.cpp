#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, nxt[105], used[105], a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "? ";

        for(int j = 1; j <= n; j++)
        {
            if(j == i)
                cout << "2 ";
            else cout << "1 ";
        }

        cout << endl;

        int x;
        cin >> x;

        if(x > 0 && x < i)
            nxt[i] = x;


        cout << "? ";

        for(int j = 1; j <= n; j++)
        {
            if(j == i)
                cout << "1 ";
            else cout << "2 ";
        }

        cout << endl;


        cin >> x;

        if(x > 0 && x < i)
            nxt[x] = i;
    }

    cout << "! ";

    for(int i = 1; i <= n; i++)
        used[nxt[i]]++;

    int x = 1;

    while(used[x])
        x++;

    for(int i = 1; i <= n; i++)
    {
        a[x] = i;
        x = nxt[x];
    }

    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}