#include <cstdio>
#include <iostream>
#include <vector>

#define x kalsdjfgh
#define y amzndlksg
#define x1 sdsdfgsfd
#define y1 djghlsers
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

typedef long long int ll;
typedef long double ld;

const int MAXN = 200000;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

int N, M;
vector<int> g[MAXN];
int dfsd[MAXN] = {0};

int getSz(int u) {
    dfsd[u] = 1;
    int res = 1;

    for (int v : g[u]) {
        if (!dfsd[v]) {
            res += getSz(v);
        }
    }

    return res;
}

bool check(int u, int sz) {
    dfsd[u] = 2;
    if (g[u].size() != sz - 1) {
        return false;
    }

    bool res = true;
    for (int v : g[u]) {
        if (dfsd[v] != 2) {
            res = (res && check(v, sz));
        }
    }

    return res;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    scanf("%d %d", &N, &M);

    int u, v;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int sz;
    for (int i = 0; i < N; ++i) {
        if (!dfsd[i]) {
            sz = getSz(i);
            if (!check(i, sz)) {
                puts("NO");
                return 0;
            }
        }
    }

    puts("YES");

    return 0;
}