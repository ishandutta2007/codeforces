#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

vector<int> g[222222];
int deg[222222];

int cc[222222];
int csize[222222];

void dfs(int v, int c) {
    cc[v] = c;
    csize[c]++;
    for (int i : g[v]) {
        if (cc[i] == -1) {
            dfs(i, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    memset(cc, -1, sizeof(cc));

    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (cc[i] == -1) {
            dfs(i, cur++);
        }
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] != csize[cc[i]] - 1) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}