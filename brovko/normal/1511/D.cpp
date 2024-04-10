#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, k, used[30][30], f;
vector <int> u, w;

void dfs(int v)
{
    w.push_back(v);

    for(int i = 0; i < k; i++)
    {
        if(used[v][i] == 0)
        {
            used[v][i] = 1;
            f++;
            dfs(i);
            break;
        }
    }
}

void dfs2()
{
    w.clear();

    for(auto to:u)
        dfs(to);

    u = w;

    /*for(auto to:u)
        cout << char(to + 'a');

    cout << endl;*/
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    u.push_back(0);

    while(f < k * k)
        dfs2();

    u.pop_back();

    for(int i = 0; i < n; i++)
        cout << char(u[i % u.size()] + 'a');
}