#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a[(int)2e5 + 5], ans = 0, root = -1;
vector <int> g[(int)2e5 + 5];
queue <int> q;
bool seen[(int)2e5 + 5] = {0};

void bfs(int x)
{
    int u = 0, v = 0;
    seen[x] = true;
    q.push(x);

    if (a[x] == x and x != root)
    {
        ++ans;
        a[x] = root;
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int ctr = 0;

        for (vector <int>::iterator i = g[cur].begin(); i != g[cur].end(); ++i)
        {
            if (!seen[*i])
            {
                seen[*i] = true;
                q.push(*i);

                if (a[*i] == *i and *i != root)
                {
                    ++ans;
                    a[*i] = root;
                }
            }

            else
            {
                if (ctr == 0)
                {
                    ++ctr;
                }

                else
                {
                    u = *i;
                    v = cur;
                }
            }
        }
    }

    if (!u)
        return;

    if (a[u] == v)
    {
        ++ans;

        if (root == -1)
        {
            a[u] = u;
            root = u;
        }

        else
            a[u] = root;
    }

    else
    {
        ++ans;

        if (root == -1)
        {
            a[v] = v;
            root = v;
        }

        a[v] = root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == i)
        {
            root = i;
            break;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != i)
        {
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
            bfs(i);
    }

    cout << ans << '\n';

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }

    return 0;
}