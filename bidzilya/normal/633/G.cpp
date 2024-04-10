#include <iostream>
#include <vector>
#include <bitset>

#include <cstdio>
using namespace std;

bool IsPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

const int MAX_M = 1e3;

int n, m;
vector<int> a;
int timer;
vector<int> tin;
vector<int> tout;
vector<vector<int>> g;

bitset<MAX_M> primes;

void DFS(int v, int p) {
    tin[v] = timer++;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        DFS(u, v);
    }
    tout[v] = timer++;
}

struct TSeg {
    void Build(const vector<int>& a, int m) {
        int n = a.size();
        T.resize(4 * n);
        Shift.resize(4 * n);
        N = n;
        M = m;
        Build(1, 0, N - 1, a);
    }

    void Build(int v, int tl, int tr, const vector<int>& a) {
        Shift[v] = 0;
        if (tl == tr) {
            T[v][a[tl]] = 1;
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm, a);
            Build(2 * v + 1, tm + 1, tr, a);
            T[v] = (T[2 * v] | T[2 * v + 1]);
        }
    }

    bitset<MAX_M> Get(int l, int r) {
        bitset<MAX_M> result;
        Get(1, 0, N - 1, l, r, result);
        return result;
    }

    void Get(int v, int tl, int tr, int l, int r, bitset<MAX_M>& result) {
        if (tl == l && tr == r) {
            result |= T[v];
        } else {
            DoShift(v, tl, tr);
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                Get(2 * v, tl, tm, l, r, result);
            } else if (l > tm) {
                Get(2 * v + 1, tm + 1, tr, l, r, result);
            } else {
                Get(2 * v, tl, tm, l, tm, result);
                Get(2 * v + 1, tm + 1, tr, tm + 1, r, result);
            }
        }
    }

    void Update(int l, int r, int shift) {
        Update(1, 0, N - 1, l, r, shift);
    }

    void Update(int v, int tl, int tr, int l, int r, int shift) {
        if (tl == l && tr == r) {
            Shift[v] += shift;
            if (Shift[v] >= M) {
                Shift[v] -= M;
            }
            DoShift(T[v], shift);
        } else {
            DoShift(v, tl, tr);
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                Update(2 * v, tl, tm, l, r, shift);
            } else if (l > tm) {
                Update(2 * v + 1, tm + 1, tr, l, r, shift);
            } else {
                Update(2 * v, tl, tm, l, tm, shift);
                Update(2 * v + 1, tm + 1, tr, tm + 1, r, shift);
            }
            T[v] = (T[2 * v] | T[2 * v + 1]);
        }
    }

    void DoShift(bitset<MAX_M>& result, int shift) {
        if (shift == 0) {
            return;
        }
        bitset<MAX_M> left = (result << (MAX_M - (M - shift)));
        left >>= (MAX_M - m);
        bitset<MAX_M> right = (result >> (M - shift));
        result = (left | right);
    }

    void DoShift(int v, int tl, int tr) {
        if (Shift[v] > 0) {
            if (tl != tr) {
                DoShift(T[2 * v], Shift[v]);
                Shift[2 * v] += Shift[v];
                if (Shift[2 * v] >= M) {
                    Shift[2 * v] -= M;
                }
                DoShift(T[2 * v + 1], Shift[v]);
                Shift[2 * v + 1] += Shift[v];
                if (Shift[2 * v + 1] >= M) {
                    Shift[2 * v + 1] -= M;
                }
            }
            Shift[v] = 0;
        }
    }

    int N;
    int M;
    vector<int> Shift;
    vector<bitset<MAX_M>> T;
};

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    tin.resize(n);
    tout.resize(n);
    timer = 0;
    DFS(0, -1);

    for (int i = 2; i < MAX_M; ++i) {
        if (IsPrime(i)) {
            primes[i] = 1;
        }
    }

    vector<int> b(2 * n);
    for (int i = 0; i < n; ++i) {
        b[tin[i]] = b[tout[i]] = a[i] % m;
    }

    TSeg st;
    st.Build(b, m);

    int q;
    cin >> q;
    for (int itr = 0; itr < q; ++itr) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v, x;
            cin >> v >> x;
            --v;
            x %= m;
            st.Update(tin[v], tout[v], x);
        } else {
            int v;
            cin >> v;
            --v;
            cout << (st.Get(tin[v], tout[v]) & primes).count() << '\n';
        }
    }
    cout.flush();

    return 0;
}