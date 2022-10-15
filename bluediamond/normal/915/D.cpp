#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 7;
int n;
int m;
vector<int> g[N];
bool u[N];
bool act[N];
int way[N];
int top;

void del(int a, int b) /// o(n)
{
    vector<int> ga = g[a];
    g[a].clear();
    for (auto &x : ga)
    {
        if (x != b)
        {
            g[a].push_back(x);
        }
    }
}

void add(int a, int b) /// o(n)
{
    g[a].push_back(b);
}

bool detect2(int a)
{
    u[a] = act[a] = 1;
    for (auto &b : g[a])
    {
        if (act[b])
        {
            return 1;
        }
        if (u[b] == 0)
        {
            bool ok = detect2(b);
            if (ok)
            {
                return 1;
            }
        }
    }
    act[a] = 0;
    return 0;
}


void detect(int a)
{
    u[a] = 1;
    act[a] = 1;
    way[++top] = a;
    for (auto &b : g[a])
    {
        if (act[b])
        {
            vector<int> nodes;
            bool gas = 0;
            for (int i = 1; i <= top; i++)
            {
                if (way[i] == b)
                {
                    gas = 1;
                }
                if (gas)
                {
                    nodes.push_back(way[i]);
                }
            }
            nodes.push_back(b);
            for (int i  = 0; i + 1 < (int) nodes.size(); i++) /// o(n)
            {
                del(nodes[i], nodes[i + 1]);
                for (int i = 1; i <= n; i++) /// o(n)
                {
                    u[i] = act[i] = 0;
                }
                bool ok = 1;
                for (int i = 1; i <= n; i++)
                {
                    if (u[i] == 0)
                    {
                        if (detect2(i))
                        {
                            ok = 0;
                        }
                    }
                }
                if (ok == 1)
                {
                    cout << "YES\n";
                    exit(0);
                }
                add(nodes[i], nodes[i + 1]);
            }
            cout << "NO\n";
            exit(0);
        }
        if (u[b] == 0)
        {
            detect(b);
        }
    }
    top--;
    act[a] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (u[i] == 0)
        {
            detect(i);
        }
    }
    cout << "YES\n";
}