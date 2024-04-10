#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

using TMatr = vector<vector<int>>;

void FillEd(TMatr& result, int n) {
    result.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
}

void FillPhiMatr(TMatr& result) {
    result.assign(2, vector<int>(2, 1));
    result[0][0] = 0;
}

void Mul(TMatr& lhs, const TMatr& rhs) {
    static long long buffer[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            buffer[i][j] = 1LL * lhs[i][0] * rhs[0][j] + 1LL * lhs[i][1] * rhs[1][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            lhs[i][j] = buffer[i][j] % MOD;
        }
    }
}

void FillBinaryPow(TMatr& result, TMatr x, long long pw) {
    FillEd(result, 2);
    while (pw > 0) {
        if (pw & 1) {
            Mul(result, x);
        }
        Mul(x, x);
        pw >>= 1;
    }
}

inline int GetPhi(long long n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    static TMatr r[2];
    FillPhiMatr(r[1]);
    FillBinaryPow(r[0], r[1], n - 2);
    return GetModSum(r[0][0][1], r[0][1][1]);
}

pair<int, int> GetNewPair(const pair<int, int>& p, const TMatr& r) {
    pair<int, int> result;
    result.first = GetModSum(
        GetModMul(p.first, r[0][0]),
        GetModMul(p.second, r[1][0])
    );
    result.second = GetModSum(
        GetModMul(p.first, r[0][1]),
        GetModMul(p.second, r[1][1])
    );

    return result;
}

class TSegTree {
public:
    void Init(const vector<int>& pows) {
        N = pows.size();
        Sum.resize(4 * N);
        Pow.resize(4 * N);
        Build(1, 0, N - 1, pows);
    }

    void Add(int l, int r, const TMatr& rm) {
        Add(1, 0, N - 1, l, r, rm);
    }

    int Get(int l, int r) {
        pair<int, int> p = Get(1, 0, N - 1, l, r);
        return p.second;
    }

private:
    int N;
    vector<pair<int, int>> Sum;
    vector<TMatr> Pow;

    void Build(int v, int tl, int tr, const vector<int>& pows) {
        FillEd(Pow[v], 2);
        if (tl == tr) {
            Sum[v].first = GetPhi(pows[tl] - 1);
            Sum[v].second = GetPhi(pows[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm, pows);
            Build(2 * v + 1, tm + 1, tr, pows);
            Sum[v].first = GetModSum(Sum[2 * v].first, Sum[2 * v + 1].first);
            Sum[v].second = GetModSum(Sum[2 * v].second, Sum[2 * v + 1].second);
        }
    }

    void Add(int v, int tl, int tr, int l, int r, const TMatr& rm) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            Sum[v] = GetNewPair(Sum[v], rm);
            Mul(Pow[v], rm);
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                Add(2 * v, tl, tm, l, r, rm);
            } else if (l > tm) {
                Add(2 * v + 1, tm + 1, tr, l, r, rm);
            } else {
                Add(2 * v, tl, tm, l, tm, rm);
                Add(2 * v + 1, tm + 1, tr, tm + 1, r, rm);
            }

            Sum[v] = Sum[2 * v];
            ModSum(Sum[v].first, Sum[2 * v + 1].first);
            ModSum(Sum[v].second, Sum[2 * v + 1].second);
        }
    }

    pair<int, int> Get(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            return Sum[v];
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                return Get(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return Get(2 * v + 1, tm + 1, tr, l, r);
            } else {
                auto p1 = Get(2 * v, tl, tm, l, tm);
                auto p2 = Get(2 * v + 1, tm + 1, tr, tm + 1, r);
                p1.first = GetModSum(p1.first, p2.first);
                p1.second = GetModSum(p1.second, p2.second);
                return p1;
            }
        }
    }

    void DoPush(int v, int tl, int tr) {
        if (tl == tr) {
            FillEd(Pow[v], 2);
            return;
        }

        Mul(Pow[2 * v], Pow[v]);
        Mul(Pow[2 * v + 1], Pow[v]);

        Sum[2 * v] = GetNewPair(Sum[2 * v], Pow[v]);
        Sum[2 * v + 1] = GetNewPair(Sum[2 * v + 1], Pow[v]);

        FillEd(Pow[v], 2);
    }
};

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    TSegTree st;
    st.Init(a);

    TMatr matrBuffer[2];

    for (int i = 0; i < m; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        --l;
        --r;
        if (tp == 1) {
            int x;
            cin >> x;

            FillPhiMatr(matrBuffer[1]);
            FillBinaryPow(matrBuffer[0], matrBuffer[1], x);
            st.Add(l, r, matrBuffer[0]);
        } else {
            cout << st.Get(l, r) << '\n';
        }
    }

    cout.flush();

    return 0;
}