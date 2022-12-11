#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 200004;

template <typename T> inline T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }
template <typename T> inline T ext_gcd(T a, T b, T &x, T &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    else { T g = ext_gcd(b, a % b, y, x); y -= (a / b) * x; return g; }
}

int n, m;
bool banned[MAXN] = { false };
std::vector<int> clique[MAXN];
std::vector<int> v;
std::vector<int> e[MAXN];
int in_deg[MAXN];
std::pair<int, int> max[MAXN];
int seq[MAXN];

inline int find_element(int p, int q)
{
    // Find such t that p * t mod m = q
    int64 s, t, g;
    g = gcd(p, gcd(q, m));
    ext_gcd(p / g, m / g, t, s);
    t = (t * (q / g) % m + m) % m;
    return t;
}

int main()
{
    scanf("%d%d", &n, &m);
    int a_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i); if (a_i == 0) a_i = m;
        banned[a_i] = true;
    }
    for (int i = 1; i <= m; ++i) if (!banned[i]) clique[gcd(m, i)].push_back(i);
    for (int i = 1; i <= m; ++i) if (!clique[i].empty()) v.push_back(i);

    for (std::vector<int>::iterator i = v.begin(); i + 1 != v.end(); ++i) {
        for (std::vector<int>::iterator j = i + 1; j != v.end(); ++j) if (*j % *i == 0) {
            e[*i].push_back(*j); ++in_deg[*j];
        }
    }

    std::queue<int> q;
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        if (in_deg[*i] == 0) { max[*i] = std::make_pair(clique[*i].size(), -1); q.push(*i); }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (std::vector<int>::iterator w = e[u].begin(); w != e[u].end(); ++w) {
            upd_max(max[*w], std::make_pair(max[u].first + (int)clique[*w].size(), u));
            if (--in_deg[*w] == 0) q.push(*w);
        }
    }

    std::pair<int, int> ans = std::make_pair(-1, -1);
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        upd_max(ans, std::make_pair(max[*i].first, *i));
    printf("%d\n", ans.first);
    int route = ans.second, ptr = ans.first;
    while (route != -1) {
        for (std::vector<int>::iterator i = clique[route].begin(); i != clique[route].end(); ++i)
            seq[--ptr] = *i;
        route = max[route].second;
    }

    for (int i = ans.first - 1; i > 0; --i) seq[i] = find_element(seq[i - 1], seq[i]);
    seq[0] %= m;
    for (int i = 0; i < ans.first; ++i) printf("%d%c", seq[i], i == ans.first - 1 ? '\n' : ' ');

    return 0;
}