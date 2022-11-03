#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

class TMinFunctor {
public:
    int operator () (int a, int b) const {
        return min(a, b);
    }
};

class TMaxFunctor {
public:
    int operator () (int a, int b) const {
        return max(a, b);
    }
};

const int MAX_LOG = 21;

template<typename TFunctor>
class TSparseTable {
public:
    void Init(const vector<int>& a) {
        N = a.size();

        Prelog.resize(N + 1);
        Prelog[1] = 0;
        for (int i = 2; i <= N; ++i) {
            Prelog[i] = Prelog[i - 1];
            if ((1 << (1 + Prelog[i])) <= i) {
                ++Prelog[i];
            }
        }

        Value.resize(N, vector<int>(MAX_LOG));
        for (int i = 0; i < N; ++i) {
            Value[i][0] = a[i];
        }

        for (int i = 1; i < MAX_LOG; ++i) {
            for (int j = 0; j < N; ++j) {
                Value[j][i] = Value[j][i - 1];
                if (j + (1 << i) < N) {
                    Value[j][i] = Functor(Value[j][i], Value[j + (1 << (i - 1))][i - 1]);
                }
            }
        }
    }

    int Get(int l, int r) const {
        int len = r - l + 1;
        int logLen = Prelog[len];

        return Functor(Value[l][logLen], Value[r - (1 << logLen) + 1][logLen]);
    }
private:
    TFunctor Functor;
    vector<vector<int>> Value;
    vector<int> Prelog;
    int N;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }

    vector<int> rev(n);
    for (int i = 0; i < n; ++i) {
        rev[p[i]] = i;
    }

    vector<int> lf(n, 0);
    vector<int> rg(n, n - 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;

        x = rev[x];
        y = rev[y];

        if (x < y) {
            rg[x] = min(rg[x], y - 1);
            lf[y] = max(lf[y], x + 1);
        } else {
            lf[x] = max(lf[x], y + 1);
            rg[y] = min(rg[y], x - 1);
        }
    }

    TSparseTable<TMaxFunctor> slf;
    slf.Init(lf);

    TSparseTable<TMinFunctor> srg;
    srg.Init(rg);

    long long result = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < i) {
            j = i;
        }

        auto isGoodSegment = [&slf, &srg] (int l, int r) {
            int lf = slf.Get(l, r);
            int rg = srg.Get(l, r);

            return lf <= l && rg >= r;
        };

        while (j < n && isGoodSegment(i, j)) {
            ++j;
        }

        result += (j - i);
    }

    printf(LLD_SPEC "\n", result);

    return 0;
}