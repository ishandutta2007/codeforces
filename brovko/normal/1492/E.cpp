#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
mt19937 rnd(time(NULL));

int n, m;
vector <int> v;

bool calc(int** a, int d)
{
    if(d > 200)
        return false;

    for(int i = 0; i < n; i++)
    {
        vector <int> dif;

        for(int j = 0; j < m; j++)
            if(a[i][j] != v[j])
                dif.pb(j);

        if(dif.size() > 2)
        {
            int ind = rnd() % dif.size();
            v[dif[ind]] = a[i][dif[ind]];

            return calc(a, d + 1);
        }
    }

//    cout << "! " << d << endl;

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int** a = new int*[n];

    for(int i = 0; i < n; i++)
        a[i] = new int[m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int j = 0; j < m; j++)
        v.pb(a[0][j]);

    if(calc(a, 0))
    {
        cout << "Yes\n";

        for(int i = 0; i < m; i++)
            cout << v[i] << ' ';
    }
    else cout << "No";
}