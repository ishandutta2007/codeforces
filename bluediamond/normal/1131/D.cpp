#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;

int n;
int m;

string a[N];

bool viz[2][N];

int t[2 * N];
int sl[2 * N];

int papa(int a)
{
        if(a == t[a])
        {
                return a;
        }
        else
        {
                t[a] = papa(t[a]);
                return t[a];
        }
}

void uni(int a, int b)
{
        a = papa(a);
        b = papa(b);
        if(a != b)
        {
                t[a] = b;
        }
}

int calc(int ty, int id)
{
        if(ty == 0)
        {
                return id;
        }
        else
        {
                return n + id;
        }
}

void dfs(int ty, int id)
{
        if(viz[ty][id]) return;
        viz[ty][id] = 1;
        int cur = 0;
        if(ty == 0)
        {
                for(int j = 1; j <= m; j++)
                {
                        if(a[id][j] == '=')
                        {
                                dfs(1, j);
                                uni(calc(1, j), calc(ty, id));
                        }
                        if(a[id][j] == '>')
                        {
                                dfs(1, j);
                                cur = max(cur, 1 + sl[papa(calc(1, j))]);
                        }
                }
        }
        else
        {
                for(int i = 1; i <= n; i++)
                {
                        if(a[i][id] == '=')
                        {
                                dfs(0, i);
                                uni(calc(0, i), calc(ty, id));
                        }
                        if(a[i][id] == '<')
                        {
                                dfs(0, i);
                                cur = max(cur, 1 + sl[papa(calc(0, i))]);
                        }
                }
        }
        sl[papa(calc(ty, id))] = max(sl[papa(calc(ty, id))], cur);
}

int f[N];
int s[N];

bool check()
{
        for(int i = 1; i <= n; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        if(a[i][j] == '=' && f[i] != s[j])
                        {
                                return 0;
                        }
                        if(a[i][j] == '>' && f[i] <= s[j])
                        {
                                return 0;
                        }
                        if(a[i][j] == '<' && f[i] >= s[j])
                        {
                                return 0;
                        }
                }
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n >> m;
        for(int i = 1; i <= n + m; i++)
        {
                t[i] = i;
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
                a[i] = "." + a[i];
        }
        for(int i = 1; i <= n; i++)
        {
                dfs(0, i);
        }
        for(int i = 1; i <= m; i++)
        {
                dfs(1, i);
        }
        int mi = (1 << 30);
        for(int i = 1; i <= n + m; i++)
        {
                sl[i]++;
        }
        for(int i = 1; i <= n; i++)
        {
                int k = papa(calc(0, i));
                mi = min(mi, sl[k]);
                ///cout<<"r"<<k<<" "<<sl[k]<<"\n";
        }
        for(int i = 1; i <= m; i++)
        {
                int k = papa(calc(1, i));
                mi = min(mi, sl[k]);
                ///cout<<"c"<<k<<" "<<sl[k]<<"\n";
        }
        mi--;
        /// cout<<"= "<<mi<<"\n";
        for(int i = 1; i <= n; i++)
        {
                int k = papa(calc(0, i));
                sl[k] -= mi;
                f[i] = sl[k];
        }
        for(int i = 1; i <= m; i++)
        {
                int k = papa(calc(1, i));
                sl[k] -= mi;
                s[i] = sl[k];
        }
        if(check() == 0)
        {
                cout << "No\n";
                return 0;
        }
        cout << "Yes\n";
        for(int i = 1; i <= n; i++)
        {
                int k = papa(calc(0, i));
                cout << sl[k] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= m; i++)
        {
                int k = papa(calc(1, i));
                cout << sl[k] << " ";
        }
        cout << "\n";
        return 0;
}
/**

2 0

**/