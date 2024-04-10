#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, c[15], a[15][200005], m;
map <vector <int>, int> q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];

        for(int j = 0; j < c[i]; j++)
            cin >> a[i][j];
    }

    cin >> m;

    while(m--)
    {
        vector <int> v;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            x--;
            v.pb(x);
        }

        q[v] = 1;
    }

    priority_queue <pair <int, vector <int> > > Q;

    vector <int> v;
    int s = 0;

    for(int i = 0; i < n; i++)
    {
        v.pb(c[i] - 1);
        s += a[i][c[i] - 1];
    }

    Q.push({s, v});
    if(q[v] > 0)
        q[v] = 2;

    while(true)
    {
        vector <int> v = Q.top().y;
        int s = Q.top().x;
//        cout << "!" << s << endl;
        Q.pop();

        if(q[v] == 0)
        {
            for(auto to:v)
                cout << to + 1 << ' ';

            return 0;
        }

        for(int i = 0; i < n; i++)
        {

            if(v[i] > 0)
            {
//                cout << "!!" << i << endl;
                s += a[i][v[i] - 1] - a[i][v[i]];
                v[i]--;



                if(q[v] < 2)
                {
                    Q.push({s, v});

                    if(q[v] > 0)
                        q[v] = 2;
                }

                v[i]++;
                s += a[i][v[i]] - a[i][v[i] - 1];
            }
        }
    }
}