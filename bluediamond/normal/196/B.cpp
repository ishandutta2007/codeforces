#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1500 + 7;
const int INF = (int) 1e9;
int n;
int m;
int a[N][N];
pair<int, int> tp[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool ok(int x, int y)
{
    x = (x % n + n) % n;
    y = (y % m + m) % m;
    return a[x][y] == 0;
}

pair<int, int> what(int x, int y)
{
    x = (x % n + n) % n;
    y = (y % m + m) % m;
    return tp[x][y];
}

void put(int x, int y)
{
    int f = x;
    int s = y;
    x = (x % n + n) % n;
    y = (y % m + m) % m;
    tp[x][y] = {f, s};
}


void dfs(int x, int y)
{
    pair<int, int> it = what(x, y);
    if (it.first != INF)
    {
        if (it == make_pair(x, y))
        {
            return;
        }
        else
        {
            cout << "Yes\n";
            exit(0);
        }
    }
    put(x, y);
    for (int k = 0; k < 4; k++)
    {
        int xn = x + dx[k];
        int yn = y + dy[k];
        if (ok(xn, yn))
        {
            dfs(xn, yn);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tp[i][j] = {INF, INF};
        }
    }
    cin >> n >> m;
    int r;
    int c;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                a[i][j] = 1;
            }
            else
            {
                if (s[j] == 'S')
                {
                    r = i;
                    c = j;
                }
            }
        }
    }
    dfs(r, c);
    cout << "No\n";
    return 0;
}