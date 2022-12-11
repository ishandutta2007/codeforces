#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tr;
vector<int> cl;
vector<int> v1, v2;

bool dfs(int v, int c)
{
    cl[v] = c;
    if (c == 0)
        v1.push_back(v);
    else
        v2.push_back(v);
        int i;
    for (i = 0; i < tr[v].size(); i++)
        if (cl[tr[v][i]] == 2)
    {
        if (!dfs(tr[v][i], 1 - c))
            return false;
    }
    else
    {
        if (cl[tr[v][i]] == c)
            return false;
    }
    return true;
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    tr.resize(n);
    cl.resize(n, 2);
    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    for (i = 0; i < n; i++)
    {
        if (cl[i] == 2)
            if (!dfs(i, 0))
            {
                cout << -1;
                return 0;
            }
    }
    cout << v1.size() << endl;
    for (i = 0; i < v1.size(); i++)
        cout << v1[i] + 1 << ' ';
    cout << endl;
    cout << v2.size() << endl;
    for (i = 0; i < v2.size(); i++)
        cout << v2[i] + 1 << ' ';
    cout << endl;
    return 0;
}