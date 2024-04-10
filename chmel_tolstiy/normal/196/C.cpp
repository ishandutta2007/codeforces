#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

const int nn = 1 << 11;

typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;

vector<int> g[nn];
vector<int> ans;
int n;
vector< pll > points;
int sub[nn];
pll pos[nn];

int subtree(int v, int p) {
    if (sub[v] >= 0) return sub[v];
    sub[v] = 0;
    for (int i = 0; i < g[v].size(); i++) if (g[v][i] != p)
        sub[v] += subtree(g[v][i], v) + 1;
    return sub[v];
}

const LD pi = acosl(-1.);

void norm(LD& a) {
    while (a < 0) a += 2*pi;
    while (a > 2*pi) a -= 2*pi;
}

void go(int v, int from, long long X, long long Y, const vector<int>& ids) {
    typedef pair<LD, int> pt;
    LD one = 1.0;
    LD a1 = atan2l((LD)Y, (LD)X);

    vector<pt> p;

    for (int i = 0; i < ids.size(); i++) {
        LD ang = atan2l((LD)points[ids[i]].second - pos[ v ].second, (LD)points[ids[i]].first - pos[ v ].first);
        ang -= a1;
        norm(ang);
        p.push_back( make_pair(ang, ids[i]) );
    }

    sort(p.begin(), p.end());
    int cur = 0;

    for (int i = 0; i < g[v].size(); i++) if (g[v][i] != from) {
        int need = subtree(g[v][i], v);
        vector<int> _id;
        for (int j = 0; j < need; j++) _id.push_back(p[cur++].second);

        ans[ p[cur].second ] = g[v][i];
        pos[ g[v][i] ] = points[ p[cur].second ];
        cur++;

        int to = g[v][i];
        go(to, v, pos[ to ].first - pos[ v ].first, pos[ to ].second - pos[ v ].second, _id);
    }
}

void solve() {
    memset(sub, -1, sizeof sub);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
    points.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}

    int mn = min_element(points.begin(), points.end()) - points.begin();

    ans.resize(n);
    ans[mn] = 1;
    pos[1] = points[mn];

    vector<int> ids;
    for (int i = 0; i < n; i++) if (i != mn) ids.push_back(i);

    go(1, -1, 0, -1, ids);

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    solve();

    return 0;
}