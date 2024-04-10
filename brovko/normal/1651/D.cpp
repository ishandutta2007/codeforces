#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x[200005], y[200005], used[200005], ax[200005], ay[200005];
map <pair <int, int>, int> m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++)
    {
        m[{x[i], y[i]}] = i + 1;
    }

    queue <int> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(m[{x[i] + dx[j], y[i] + dy[j]}] == 0)
            {
                used[i] = 1;
                ax[i] = x[i] + dx[j];
                ay[i] = y[i] + dy[j];
                q.push(i);
            }
        }
    }

    while(!q.empty())
    {
        int i = q.front();
        q.pop();

        for(int j = 0; j < 4; j++)
        {
            int nx = x[i] + dx[j];
            int ny = y[i] + dy[j];

            int k = m[{nx, ny}] - 1;

            if(used[k] == 0)
            {
                used[k] = 1;
                ax[k] = ax[i];
                ay[k] = ay[i];

                q.push(k);
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ax[i] << ' ' << ay[i] << "\n";
}