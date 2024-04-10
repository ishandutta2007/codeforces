#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") ->" << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1505;

V<array<int, 3>> d[2][N], r[2][N], rd[2][N];
int ans[N], a[N][N];
int vis[N * N];

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j], a[i][j]--;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            rd[i & 1][j] = {{a[i][j], i, j}};
            auto dist = [&] (array<int, 3> p) {
                return max(p[1] - i, p[2] - j);
            };
            auto merge = [&] (V<array<int, 3>> a, V<array<int, 3>> b, V<array<int, 3>>& c) {
                c.clear();
                auto add = [&] (array<int, 3> p) {
                    if(vis[p[0]] == 0) {
                        vis[p[0]] = 1;
                        c.PB(p);
                    }
                };
                for(int i = 0, j = 0; i < int(a.size()) || j < int(b.size());) {
                    if(j == int(b.size()) || (i < int(a.size()) && dist(a[i]) < dist(b[j]))) {
                        add(a[i++]);
                    } else {
                        add(b[j++]);
                    }
                    if(int(c.size()) == q + 1) break;
                }
                for(auto p:c) vis[p[0]] = 0;
            };
            merge(rd[i & 1][j], r[i & 1][j + 1], r[i & 1][j]);
            merge(rd[i & 1][j], d[i & 1 ^ 1][j], d[i & 1][j]);
            merge(rd[i & 1][j], r[i & 1][j + 1], rd[i & 1][j]);
            merge(rd[i & 1][j], d[i & 1 ^ 1][j], rd[i & 1][j]);
            merge(rd[i & 1][j], rd[i & 1 ^ 1][j + 1], rd[i & 1][j]);
            if(int(rd[i & 1][j].size()) > q) {
                ans[min({n - i, n - j, dist(rd[i & 1][j].back())})]++;
            } else {
                ans[min(n - i, n - j)]++;
            }
        }
    }
    for(int i = n; i >= 1; i--)
        ans[i] += ans[i + 1];
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';

}