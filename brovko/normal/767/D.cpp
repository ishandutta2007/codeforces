#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[1000005], b[1000005];
vector <pair <int, int> > ans;

bool comp(int i, int j)
{
    return (i > j);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            ans.push_back({b[i], i});
        }

    int L = -1;
    int R = m + 1;

    sort(b, b + m, comp);
    sort(a, a + n, comp);

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        vector <int> v;

        /*for(int i = 0; i < n; i++)
            v.push_back(a[i]);

        for(int j = 0; j < M; j++)
            v.push_back(b[j]);


        sort(v.begin(), v.end());*/

        int y = n - 1;
        int z = M - 1;

        for(int i = 0; i < n + M; i++)
        {
            if(y < 0)
            {
                v.push_back(b[z]);
                z--;
            }
            else if(z < 0)
            {
                v.push_back(a[y]);
                y--;
            }
            else if(a[y] > b[z])
            {
                v.push_back(b[z]);
                z--;
            }
            else
            {
                v.push_back(a[y]);
                y--;
            }
        }

        int f = 1;

        for(int i = 0; i < v.size(); i += k)
            if(v[i] < i / k)
                f = 0;

        if(f)
            L = M;
        else R = M;
    }

    cout << L << "\n";

    if(L > 0)
        {
            sort(ans.begin(), ans.end());

            for(int i = (int)ans.size() - 1; i >= (int)ans.size() - L; i--)
                cout << ans[i].second + 1 << ' ';
        }
}