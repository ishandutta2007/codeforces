#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, a[200005], ans;
map <int, int> used;
queue <pair <int, int> > q;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        q.push({a[i], 0});
        used[a[i]]++;
    }

    while(true)
    {
        int x = q.front().first;
        int y = q.front().second;
        if(used[x] == 0)
        {
            used[x] = 1;
            ans += y;
            v.push_back(x);
        }

        if(used[x-1] == 0)
            q.push({x-1, y+1});
        if(used[x+1] == 0)
            q.push({x+1, y+1});

        q.pop();

        if(v.size() == m)
        {
            cout << ans << endl;
            for(auto to:v)
                cout << to << ' ';
            return 0;
        }
    }
}