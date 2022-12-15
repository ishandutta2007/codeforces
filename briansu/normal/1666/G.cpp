#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define double long double

struct Point {
    double x, y, z;
    Point(double _x = 0, double _y = 0, double _z = 0): x(_x), y(_y), z(_z) {}
};
Point operator-(Point p1, Point p2)
{ return Point(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z); }
Point operator+(Point p1, Point p2)
{ return Point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z); }
Point operator*(Point p1, double p)
{ return Point(p1.x * p, p1.y * p, p1.z * p); }
Point operator/(Point p1, double p)
{ return Point(p1.x / p, p1.y / p, p1.z / p); }
Point cross(Point p1, Point p2)
{ return Point(p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x); }
double dot(Point p1, Point p2) 
{ return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z; }
double abs(Point a) 
{ return sqrt(dot(a, a)); }
double area(Point a, Point b, Point c) {
    return abs(cross(b - a, c - a)) / 2;
}

struct Query {
    int h, p, i;
    bool operator<(const Query &q) const {
        return h > q.h;
    }
} query[100005];
double ans[100005];

Point arr[100005];
pii event[100005];

vector<int> G[100005];
int boss[100005];
Point func[100005];

int finds(int u) {
    if (u == boss[u]) return u;
    return boss[u] = finds(boss[u]);
}

void Union(int u, int v) {
    u = finds(u), v = finds(v);
    if (u == v) return;
    boss[u] = v;
    func[v] = func[v] + func[u];
}

double get_val(Point f, double h) {
    return dot(f, Point(h * h, h, 1));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = Point(x, y, z);
        event[i] = pii(z, i);
    }
    iota(boss + 1, boss + n + 1, 1);

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int p[3];
        cin >> p[0] >> p[1] >> p[2];
        sort(p, p + 3, [&](int a, int b) {
            return arr[a].z > arr[b].z;
        });
        int a = p[0], b = p[1], c = p[2];
        G[c].pb(b);
        G[b].pb(a);
        Point prev = Point(0, 0, 0);
        double up = 0;
        if (arr[a].z != arr[b].z) {
            Point mid = (arr[a] * (arr[b].z - arr[c].z) + arr[c] * (arr[a].z - arr[b].z)) / (arr[a].z - arr[c].z);
            double A = area(arr[a], arr[b], mid); 
            double t = (arr[a].z - arr[b].z) * (arr[a].z - arr[b].z);
            prev = Point(A / t, -2 * arr[a].z * A / t, arr[a].z * arr[a].z * A / t);
            up = A;
            func[a] = func[a] + prev;
        }
        if (arr[b].z != arr[c].z) {
            Point mid = (arr[a] * (arr[b].z - arr[c].z) + arr[c] * (arr[a].z - arr[b].z)) / (arr[a].z - arr[c].z);
            double A = area(arr[b], arr[c], mid); 
            double t = (arr[b].z - arr[c].z) * (arr[b].z - arr[c].z);
            func[b] = func[b] - prev;
            func[b] = func[b] + Point(0, 0, up);
            prev = Point(-A / t, 2 * arr[c].z * A / t, A - arr[c].z * arr[c].z * A / t);
            func[b] = func[b] + prev;
            up = A;
        }
        func[c] = func[c] - prev;
        func[c] = func[c] + Point(0, 0, up);
        if (arr[a].z == arr[c].z)
            func[c] = func[c] + Point(0, 0, area(arr[a], arr[b], arr[c]));
    }

    cin >> q;
    for (int i = 1; i <= q; ++i)
        cin >> query[i].h >> query[i].p, query[i].i = i;
    sort(query + 1, query + q + 1);

    sort(event + 1, event + n + 1, greater<pii>()); 
    for (int i = 1, j = 1; i <= q; ++i) {
        while (j <= n && event[j].X > query[i].h) {
            for (int p : G[event[j].Y]) {
                Union(event[j].Y, p);
            }
            ++j;
        }
        if (query[i].h >= arr[query[i].p].z)
            ans[query[i].i] = -1;
        else {
            ans[query[i].i] = get_val(func[finds(query[i].p)], query[i].h);
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << fixed << setprecision(15) << ans[i] << "\n";
}