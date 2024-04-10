#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define PRIM 3
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int n, m;
int u, v;
char c;
int col[110000];

vector<P> edge[110000];

vector<int> nodes[3];
bool ng;

void output(vector<int> xs)
{
    printf("%d\n", int(xs.size()));
    for (auto x : xs)
        printf("%d ", x);
    puts("");
}

void dfs(int x, char s, int c)
{
    col[x] = c;
    nodes[c].push_back(x);
    for (auto p : edge[x]) {
        int to = p.first;
        if (p.second == s) {
            if (col[to]) {
                if (col[to] != col[x])
                    ng = true;
            }
            else
                dfs(to, s, col[x]);
        }
        else {
            if (col[to]) {
                if (col[to] == col[x])
                    ng = true;
            }
            else
                dfs(to, s, 3 - col[x]);
        }
    }
}

vector<int> solve(char c)
{
    vector<int> res;
    fill(col, col + (n + 1), 0);
    for (int i = 1; i <= n; i++) {
        if (col[i])
            continue;
        ng = false;
        nodes[1].clear();
        nodes[2].clear();
        dfs(i, c, 1);
        if (ng)
            return vector<int>(n + 1);
        if (nodes[1].size() > nodes[2].size())
            swap(nodes[1], nodes[2]);
        for (auto x : nodes[1])
            res.push_back(x);
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &u, &v, &c);
        edge[u].push_back(P(v, c));
        edge[v].push_back(P(u, c));
    }

    auto ans1 = solve('R');
    auto ans2 = solve('B');
    if (ans1.size() == n + 1 && ans2.size() == n + 1) {
        puts("-1");
    }
    else if (ans1.size() < ans2.size())
        output(ans1);
    else
        output(ans2);
    return 0;
}