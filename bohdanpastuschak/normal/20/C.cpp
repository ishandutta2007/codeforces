using namespace std;
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define pq priority_queue
#define um unordered_map
#define F first
#define B begin()
#define E end()
#define sz size()
#define S second
#define mp make_pair
#define pb push_back
#define inf 1000000000

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef um<int, int> umii;
typedef um<char, int> umci;
typedef map<char, int> mci;
typedef map<int, int> mii;

int n;
void dijkstra(vii g[])
{
    int a, b, c, e, f, i;
    long long d[n + 1], p[n + 1];
    for (i = 1; i <= n; i++) {
        d[i] = inf * (long long) inf;
        p[i] = -1;
    }
    d[1] = 0;
    pq<ii, vii, greater<ii>> q;
    q.push({ 0, 1 });
    while (!q.empty()) {
        a = q.top().S;
        if (a == n)
            break;
        b = q.top().F;
        q.pop();
        //if (b != d[a])
        //    continue;
        c = g[a].sz;
        for (i = 0; i < c; i++) {
            f = g[a][i].F;
            e = g[a][i].S;
            if (d[a] + e < d[f]) {
                d[f] = d[a] + e;
                p[f] = a;
                q.push({ d[f], f });
            }
        }
    }
    if (p[n] == -1)
        cout << -1;
    else {
        vi path;
        i = p[n];
        while (i != 1) {
            path.pb(i);
            i = p[i];
        }
        cout << 1;
        for (i = path.sz - 1; i >= 0; i--)
            cout << " " << path[i];
        cout << " " << n;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int m, u, v, w;
    cin >> n >> m;
    n;
    vii g[n + 1];
    while (m--) {
        cin >> u >> v >> w;
        g[u].pb({ v, w });
        g[v].pb({ u, w });
    }
    dijkstra(g);

    return 0;
}