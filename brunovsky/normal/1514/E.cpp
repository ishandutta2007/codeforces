#include <bits/stdc++.h>

#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<vector<bool>> dir;

bool DIRECTED(int u, int v) {
#ifdef LOCAL
    return dir[u][v];
#endif
    cout << 1 << ' ' << u << ' ' << v << endl;
    int uv;
    cin >> uv;
    return uv == 1;
}

bool ANY_PASSAGE(int s, const vector<int>& t) {
#ifdef LOCAL
    for (int v : t) {
        if (dir[s][v]) {
            return true;
        }
    }
    return false;
#endif
    int k = t.size();
    cout << 2 << ' ' << s << ' ' << k;
    for (int v : t) {
        cout << ' ' << v;
    }
    cout << endl;
    int is;
    cin >> is;
    return is == 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

#ifdef LOCAL
        bernoulli_distribution coin(0.5);
        mt19937 mt(random_device{}());
        dir.assign(N, vector<bool>(N));
        for (int u = 0; u < N; u++) {
            for (int v = u + 1; v < N; v++) {
                dir[v][u] = !(dir[u][v] = coin(mt));
            }
        }
#endif

        // find a hamiltonian path first
        vector<vector<int>> paths(N);
        for (int i = 0; i < N; i++) {
            paths[i] = {i};
        }

        int P = paths.size();
        while (P > 1) {
            for (int p = P & 1; p + 1 < P; p += 2) {
                const auto& a = paths[p];
                const auto& b = paths[p + 1];
                int A = a.size(), B = b.size();
                int i = 0, j = 0;
                vector<int> c;

                // so the paths go a[0]->a[1]... b[0]->b[1]...
                // If there is a path a[0]->b[0] we add a[0] first and pop it from a
                while (i < A && j < B) {
                    if (DIRECTED(a[i], b[j])) {
                        c.push_back(a[i++]);
                    } else {
                        c.push_back(b[j++]);
                    }
                }
                c.insert(end(c), begin(a) + i, end(a));
                c.insert(end(c), begin(b) + j, end(b));
                paths[(p + 1) / 2] = move(c);
            }
            P = (P + 1) / 2;
            paths.resize(P);
        }
        debug(paths);
        const auto& a = paths[0];

        vector<vector<bool>> adj(N, vector<bool>(N));
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                adj[a[i]][a[j]] = true;
            }
        }

        vector<int> boundary(N);

        // now go from a[N-1] to a[0]
        for (int i = N - 1, R = i - 1; i >= 0; i--, R = min(R, i - 1)) {
            while (R >= 0 && ANY_PASSAGE(a[i], vector<int>(begin(a), begin(a) + R + 1))) {
                R--;
            }
            boundary[i] = R;
        }

        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j > boundary[i]; j--) {
                boundary[i] = min(boundary[i], boundary[j]);
                adj[a[i]][a[j]] = true;
            }
        }

        cout << 3 << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << int(adj[i][j]);
            }
            cout << '\n';
        }
        cout.flush();

        int ok;
        cin >> ok;
        assert(ok == 1);
    }
    return 0;
}