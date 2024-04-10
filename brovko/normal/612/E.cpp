#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, p[1000005], used[1000005], q[1000005];
vector <vector <int> > c;

bool cmp(vector <int> i, vector <int> j)
{
    return (i.size() < j.size());
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            vector <int> v;
            int x = i;

            while(used[x] == 0)
            {
                used[x] = 1;
                v.pb(x);
                x = p[x];
            }

            c.pb(v);
        }
    }

    sort(c.begin(), c.end(), cmp);

    for(int i = 0; i < c.size(); i++)
    {
        if(c[i].size() % 2)
        {
            int x = c[i].size() / 2 + 1;

            for(int j = 0; j < c[i].size(); j++)
            {
                if(j < x - 1)
                    q[c[i][j]] = c[i][j + x];
                else q[c[i][j]] = c[i][j - x + 1];
            }
        }
        else
        {
            if(i + 1 == c.size() || c[i + 1].size() != c[i].size())
            {
                cout << -1;
                return 0;
            }

            for(int j = 0; j < c[i].size(); j++)
            {
                q[c[i][j]] = c[i + 1][j];
                q[c[i + 1][j]] = c[i][(j + 1) % c[i].size()];
            }

            i++;
        }
    }

    for(int i = 0; i < n; i++)
        cout << q[i] + 1 << ' ';
}