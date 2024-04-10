#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[100005];
map <int, int> used;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        used[a[i]] = 1;
    }

    vector <int> v;

    for(int i = 1; i <= 1e9; i++)
    {
        if(used[i] == 0 && m >= i)
            {
                v.push_back(i);
                m -= i;
            }

        if(m < i)
        {
            cout << v.size() << "\n";

            for(auto to:v)
                cout << to << ' ';

            return 0;
        }
    }
}