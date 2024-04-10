#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, m;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
void add(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int u[MAXN], v[MAXN];

bool vis[MAXN];
int col[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", u + i, v + i);
        add(u[i], v[i]);
        add(v[i], u[i]);
    }
    queue<int> q;
    q.push(1); vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            if (vis[e[i]])
            {
                if (col[e[i]] == col[x])
                    return printf("NO\n"), 0;
            }
            else
            {
                col[e[i]] = col[x] ^ 1;
                q.push(e[i]);
                vis[e[i]] = 1;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= m; i++)
    putchar(48 + col[u[i]]);
        // if (!col[u[i]])
        //     printf("%d %d\n", u[i], v[i]);
        // else
        //     printf("%d %d\n", v[i], u[i]);
}