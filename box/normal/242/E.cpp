// writer: w33z8kqrqk8zzzx33
#include <cstdio>
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
//#define int ll
const int MOD = 1000000007;

using T=int;
using T2=int;

class SST {
public:
    const T inf = 0;
    T m(T x, T y) { return x+y; }
    int d; T sum;
    SST* ch[2];
    SST(int D) : d(D) {
        sum = inf;
        hastag = 0;
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
    ~SST() {
        if (ch[0]) delete ch[0];
        if (ch[1]) delete ch[1];
    }
    bool hastag; T2 tag;
    inline void upds() {
        sum = 0;
        if(ch[0]) sum += ch[0]->sum;
        if(ch[1]) sum += ch[1]->sum;
    }
    inline void cine(const int& v) {
        if(!ch[v]) ch[v] = new SST(d-1);
    }
    inline void tagit(const T2& t) {
        hastag = !hastag;
        tag = t;
        sum = (1<<d)-sum;
    }
    void pushdown() {
        if(!hastag || !d) return;
        cine(0); ch[0]->tagit(tag);
        cine(1); ch[1]->tagit(tag);
        hastag = 0;
    }
    void inc(const int& i, const T& v) {
        pushdown();
        if (!d) { sum = m(sum, v); return; }
        bool cv = i & (1ll << (d - 1));
        cine(cv); ch[cv]->inc(i, v);
        upds();
    }
    T prepsum(const int& i) {
        pushdown();
        if (!d) return sum;
        T ans = inf;
        bool cv = i & (1ll << (d - 1));
        if (ch[cv]) ans = ch[cv]->prepsum(i);
        if (cv && ch[0]) ans = m(ans, ch[0]->sum);
        return ans;
    }
    T sufpsum(const int& i) {
        pushdown();
        if (!d) return sum;
        T ans = inf;
        bool cv = i & (1ll << (d - 1));
        if (ch[cv]) ans = ch[cv]->sufpsum(i);
        if (!cv && ch[1]) ans = m(ans, ch[1]->sum);
        return ans;
    }
    T psum(const int& l, const int& r) {
        pushdown();
        if (!d) return sum;
        bool cv1 = l & (1ll << (d - 1));
        bool cv2 = r & (1ll << (d - 1));
        if (cv1==cv2) {
            if(!ch[cv1]) return inf;
            return ch[cv1]->psum(l, r);
        }
        T ans = inf;
        if(ch[0]) ans = m(ans, ch[0]->sufpsum(l));
        if(ch[1]) ans = m(ans, ch[1]->prepsum(r));
        return ans;
    }
    void preset(const int& i, const T2& t) {
        pushdown();
        if (!d) { tagit(t); return; }
        bool cv = i & (1ll << (d - 1));
        cine(cv); ch[cv]->preset(i, t);
        if (cv) {
            cine(0);
            ch[0]->tagit(t);
        }
        upds();
    }
    void sufset(const int& i, const T2& t) {
        pushdown();
        if (!d) { tagit(t); return; }
        bool cv = i & (1ll << (d - 1));
        cine(cv); ch[cv]->sufset(i, t);
        if (!cv) {
            cine(1);
            ch[1]->tagit(t);
        }
        upds();
    }
    void set(const int& l, const int& r, const T2& t) {
        pushdown();
        if (!d) { tagit(t); return; }
        bool cv1 = l & (1ll << (d - 1));
        bool cv2 = r & (1ll << (d - 1));
        if (cv1==cv2) {
            cine(cv1); ch[cv1]->set(l, r, t);
            upds();
            return;
        }
        cine(0); ch[0]->sufset(l, t);
        cine(1); ch[1]->preset(r, t);
        upds();
    }
};

SST* BIT[20];

signed main() {
    rep(i, 20) BIT[i] = new SST(17);
    int n; scanf("%d", &n);
    rep1(i, n) {
        int v; scanf("%d", &v);
        rep(b, 20) if(v & (1<<b)) BIT[b]->inc(i, 1);
    }
    int m; scanf("%d", &m);
    rep(i, m) {
        int ty, l, r; scanf("%d%d%d", &ty, &l, &r);
        if(ty == 1) {
            ll ans = 0;
            rep(b, 20) ans += (1ll << b) * BIT[b]->psum(l, r);
            printf("%lld\n", ans);
        } else {
            int x; scanf("%d", &x);
            rep(b, 20) if(x & (1<<b)) BIT[b]->set(l, r, 1);
        }
    }
}