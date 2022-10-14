// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
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
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

using T=pair<int, int>;

class SST {
public:
    const T inf = {0, 0};
    T m(T x, T y) { return max(x, y); }
    int d; T sum;
    SST* ch[2];
    SST(int D) : d(D) {
        sum = inf;
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
    ~SST() {
        if (ch[0]) delete ch[0];
        if (ch[1]) delete ch[1];
    }
    void inc(const ll& i, const T& v) {
        if (!d) { sum = m(sum, v); return; }
        bool cv = i & (1ll << (d - 1));
        if (!ch[cv]) ch[cv] = new SST(d - 1);
        ch[cv]->inc(i, v);
        sum = ch[cv]->sum; if(ch[1-cv]) sum = m(sum, ch[1-cv]->sum);
    }
    T prepsum(const ll& i) {
        if (!d) return sum;
        T ans = inf;
        bool cv = i & (1ll << (d - 1));
        if (ch[cv]) ans = ch[cv]->prepsum(i);
        if (cv && ch[0]) ans = m(ans, ch[0]->sum);
        return ans;
    }
    T sufpsum(const ll& i) {
        if (!d) return sum;
        T ans = inf;
        bool cv = i & (1ll << (d - 1));
        if (ch[cv]) ans = ch[cv]->sufpsum(i);
        if (!cv && ch[1]) ans = m(ans, ch[1]->sum);
        return ans;
    }
    T psum(const ll& l, const ll& r) {
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
};

ll aray[100005];
int pre[100005];
SST* v = new SST(60);

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; ll d; cin >> d;
    rep1(i, n) {
        cin >> aray[i];
        aray[i] += d;
    }
    int bes = 0, optend = 0;
    rep1(i, n) {
        pii opt = v->m(v->prepsum(aray[i]-d), v->sufpsum(aray[i]+d));
        opt.fi++; pre[i] = opt.se;
        if(bes < opt.fi) {
            bes = opt.fi;
            optend = i;
        }
        v->inc(aray[i], {opt.fi, i});
    }
    stack<int> st;
    while(optend) {
        st.push(optend);
        optend = pre[optend];
    }
    cout << st.size() << endl;
    bool f = true;
    while(st.size()) {
        if(!f) cout << ' ';
        f = 0;
        cout << st.top(); st.pop();
    }
    cout << endl;
}