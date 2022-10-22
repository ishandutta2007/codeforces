#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[2005][2005];
vector <int> v1, v2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << "? " << 1 << endl;

    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        if(d == 1)
        {
            a[0][i] = 1;
            a[i][0] = 1;
        }

        if(i > 0 && d % 2 == 0)
            v1.pb(i);

        if(d % 2)
            v2.pb(i);
    }

    if(v1.size() > v2.size())
        swap(v1, v2);

    for(auto to:v1)
    {
        cout << "? " << to + 1 << endl;

        for(int i = 0; i < n; i++)
        {
            int d;
            cin >> d;

            if(d == 1)
            {
                a[to][i] = 1;
                a[i][to] = 1;
            }
        }
    }

    cout << "!" << endl;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i][j] == 1)
            {
                cout << i + 1 << ' ' << j + 1 << endl;
            }
}