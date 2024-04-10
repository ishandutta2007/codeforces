#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = (int) 2e5 + 7;
int n;
int a[N];
int sol[N];
vector<int> b[2];
vector<int> intr[N];
int dist[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i] % 2].push_back(i);
        sol[i] = -1;
        if (i - a[i] >= 1)
        {
            intr[i - a[i]].push_back(i);
        }
        if (i + a[i] <= n)
        {
            intr[i + a[i]].push_back(i);
        }
    }
    for (int p = 0; p <= 1; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = -1;
        }
        queue<int> q;
        for (auto &i : b[p])
        {
            dist[i] = 0;
            q.push(i);
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto &y : intr[x])
            {
                if (dist[y] == -1)
                {
                    dist[y] = 1 + dist[x];
                    q.push(y);
                }
            }
        }
        for (auto &i : b[1 - p])
        {
            sol[i] = dist[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
}