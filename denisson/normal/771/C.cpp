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
int glob[5];
int out[5];
int loc[222222][5];
int n, k;

lint cur_ans = 0;

lint ans = 0;

void dfs(int v, int p, int dep) {
    glob[dep % k]++;
    loc[v][dep % k]++;
    cur_ans += (dep + k - 1) / k;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v, dep + 1);
        for (int j = 0; j < k; j++) {
            loc[v][j] += loc[i][j];
        }
    }
}


void go(int v, int p, int dep) {
    ans += cur_ans;
    int oout[5];
    int nout[5] = {0, 0, 0, 0, 0};
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        lint o_ans = cur_ans;
        cur_ans -= loc[i][(dep + 1) % k];

        for (int j = 0; j < k; j++) {
            nout[(j + 1) % k] = out[j];
            oout[j] = out[j];
        }

        for (int j = 0; j < k; j++) {
            int x = (dep - 1 + j + k) % k;
            nout[j] += loc[v][x] - loc[i][x];
        }

        for (int j = 0; j < k; j++) {
            out[j] = nout[j];
        }

        cur_ans += out[1];
        if (k == 1) {
            cur_ans += out[0];
        }

        go(i, v, dep + 1);
        cur_ans = o_ans;
        for (int j = 0; j < k; j++) {
            out[j] = oout[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, k);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1, 0);

    go(0, -1, 0);

    if (ans & 1) {
        cout << ":(" << endl;
    }

    cout << ans / 2;

    return 0;
}