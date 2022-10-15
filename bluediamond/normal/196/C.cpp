#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1500 + 7;
int n;
int x[N];
int y[N];
int what_vertex[N];
int sub[N];
vector<int> g[N];

void build_sub(int a, int p)
{
    sub[a] = 1;
    for (auto &b : g[a])
    {
        if (b != p)
        {
            build_sub(b, a);
            sub[a] += sub[b];
        }
    }
}

int id;

ll lol(int i, int j)
{
    return (ll) (x[i] - x[j]) * (y[i] + y[j]);
}

ll lol(int i, int j, int k)
{
    return lol(i, j) + lol(j, k) + lol(k, i);
}

bool cmp(int i, int j)
{
    return lol(id, i, j) > 0;
}

void put(vector<int> pts, int a, int p)
{
    int i = pts[0];
    for (auto &j : pts)
    {
        if (x[j] < x[i])
        {
            i = j;
        }
    }
    what_vertex[i] = a;
    vector<int> aux;
    for (auto &j : pts)
    {
        if (j != i)
        {
            aux.push_back(j);
        }
    }
    pts = aux;
    id = i;
    sort(pts.begin(), pts.end(), cmp);
    for (auto &b : g[a])
    {
        if (b != p)
        {
            aux.clear();
            for (int j = 1; j <= sub[b]; j++)
            {
                aux.push_back(pts.back());
                pts.pop_back();
            }
            put(aux, b, a);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> pts;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        pts.push_back(i);
    }
    build_sub(1, -1);
    put(pts, 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << what_vertex[i] << " ";
    }
    cout << "\n";
    return 0;
}