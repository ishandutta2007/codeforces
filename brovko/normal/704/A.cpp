#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, q, t, x, used[300005], y, k, mex;
vector <int> v[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    while(q--)
    {
        cin >> t >> x;

        if(t == 1)
        {
            v[x].push_back(y);
            y++;
        }

        if(t == 2)
        {
            for(auto to:v[x])
            {
                if(used[to] == 0)
                {
                    used[to] = 1;
                    k++;
                }
            }

            v[x].clear();
        }

        if(t == 3)
        {
            while(mex < x)
            {
                if(used[mex] == 0)
                {
                    used[mex] = 1;
                    k++;
                }

                mex++;
            }
        }

        cout << y - k << "\n";
    }
}