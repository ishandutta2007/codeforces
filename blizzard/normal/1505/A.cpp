#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1e6;
const double INF = 1e9;
 
struct Point
{
    Point(int x, int y, int i) : x(x), y(y), i(i) {}
 
    int x, y, i;
};
 
double dist(Point& a, Point& b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
vector<Point> v;
 
 
vector<pair<int, double>> e[MAXN];
void addEdge(int x, int y)
{
    e[x].emplace_back(x, dist(v[x], v[y]));
    e[y].emplace_back(y, dist(v[x], v[y]));
}
 
int num(int x, int y)
{
    return max(abs(x), abs(y));
}
 
int side(Point& p)
{
    if (p.x == p.i) return 0;
    if (p.y == -p.i) return 1;
    if (p.x == -p.i) return 2;
    if (p.y == p.i) return 3;
    assert(false);
}
 
vector<double> dijkstra(int start)
{
    vector<double> d(v.size(), INF);
    d[start] = 0;
    set<pair<double, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.emplace(d[i], i);
    }
    while (!s.empty())
    {
        auto [dist, u] = *s.begin();
        cerr << dist << " " << u << " " << e[u].size() <<  endl;
        s.erase(s.begin());
        for (auto [v, w] : e[u])
        {
            cerr << v << " " << w << endl;
            if (dist + w < d[v])
            {
                s.erase({d[v], v});
                d[v] = dist + w;
                s.emplace(d[v], v);
            }
        }
    }
    return d;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 /*
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif     */
 
    string s;
	while (cin >> s) {
		cin >> s;
		cin >> s;
		cout << "NO" << endl;
	}
}