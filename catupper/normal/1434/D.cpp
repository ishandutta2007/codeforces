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

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;


vector<P> edge[550000];

void dfs(int x, vector<int> &dep, int last = -1){
    if(last == -1)dep[x] = 0;
    for(auto [to, _]: edge[x]){
        if(to == last)continue;
        dep[to] = dep[x] + 1;
        dfs(to, dep, x);
    }
}

int n;
int u[550000];
int v[550000];
int t[550000];


P op(P x, P y)
{
    if(x.first == INF)return y;
    if(y.first == INF)return x;
    return {max({x.first, x.second, y.first, y.second}),
            min({x.first, x.second, y.first, y.second})};
}

P e()
{
    return {INF, INF};
}

P mapping(bool x, P y)
{
    if(y.first == INF)return y;
    return x ? P(-y.first, -y.second) : y;
}

bool composition(bool x, bool y)
{
    return x ^ y;
}

bool id()
{
    return false;
}

using lazy_seg = atcoder::lazy_segtree<P, op, e, bool, mapping, composition, id>;
struct Euler{
    lazy_seg seg;
    vector<int> in, out;
    vector<P> tmp;
    int p;

    void dfs2(int v, int last = -1, int dep = 0, int fliped = 1){
        in[v] = p++;
        tmp[in[v]] =  P(dep * fliped, dep * fliped);
        for(auto [to, ind]:edge[v]){
            if(to == last)continue;            
            dfs2(to, v, dep + 1, fliped * (t[ind]?-1:1));
        }
        out[v] = p;
    }
    
    Euler(int v):p(0),in(n+1), out(n+1), tmp(n){
        dfs2(v);
        seg = lazy_seg(tmp);
    }
    void flip(int u, int v){
        if(in[u] < in[v])swap(u, v);
        seg.apply(in[u], out[u], true);
    }

    int get_max(){
        auto res = seg.all_prod();
        return max(res.first, res.second);
    }
};

int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n-1;i++){
        scanf("%d%d%d",&u[i],&v[i],&t[i]);
        edge[u[i]].emplace_back(v[i], i);
        edge[v[i]].emplace_back(u[i], i);
    }
    vector<int> dep1(n+1), dep2(n+1);
    dfs(1, dep2);
    int farest1 = 1;
    for(int i = 1;i <= n;i++){
        if(dep2[i] > dep2[farest1])farest1 = i;
    }

    dfs(farest1, dep1);
    int farest2 = 1;
    for(int i = 1;i <= n;i++)if(dep1[i] > dep1[farest2])farest2 = i;
    dfs(farest2, dep2);
    
    Euler tree1(farest1), tree2(farest2);
    
    int m;
    scanf("%d", &m);
    for(int i = 0;i < m;i++){
        int q;
        scanf("%d", &q);
        tree1.flip(u[q], v[q]);
        tree2.flip(u[q], v[q]);
        printf("%d\n", max(tree1.get_max(), tree2.get_max()));
    }    
    return 0;
}