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

const ll inff = -1;

class SST {
public:
    int dep; ll sum;
    SST* ch[2];
    SST(int dep) : dep(dep) {
        sum = inff;
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
    ~SST() {
        if (ch[0])
            delete ch[0];
        if (ch[1])
            delete ch[1];
    }
    void inc(int val, ll diff) {
        if (!dep) { sum = max(sum, diff); return; }
        bool cv = val & (1ll << (dep - 1));
        if (!ch[cv]) ch[cv] = new SST(dep - 1);
        ch[cv]->inc(val, diff);
        sum = ch[cv]->sum;
        if(ch[1-cv]) sum = max(sum, ch[1-cv]->sum);
    }
    ll psum(int val) {
        if (!dep) return sum;
        ll ans = inff;
        bool cv = val & (1ll << (dep - 1));
        if (ch[cv]) ans = ch[cv]->psum(val);
        if(cv && ch[0]) ans = max(ans, ch[0]->sum);
        return ans;
    }
};

int m[500005];
int n;
int an[500005];
ll beforeturn[500005], afterturn[500005];

ll test(int turndown, bool se) {
    int cur = m[turndown]; ll ans = m[turndown];
    if(se) an[turndown] = cur;
    for(int i=turndown-1; i>=0; i--) {
        cur = min(cur, m[i]);
        if(se) an[i] = cur;
        ans += cur;
    }
    cur = m[turndown];
    for(int i=turndown+1; i<n; i++) {
        cur = min(cur, m[i]);
        if(se) an[i] = cur;
        ans += cur;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, n) {
        int v; cin >> v;
        m[i] = v;
    }
    SST* A = new SST(33);
    rep(i, n) {
        A->inc(m[i], i);
        int t = m[i];
        int ans = A->psum(m[i]-1);
        if(ans == inff) ans = -1;
        beforeturn[i] = 1ll*t*(i-ans);
        if(ans != -1) beforeturn[i] += beforeturn[ans];
    }
    SST* B = new SST(33);
    for(int i=n-1; i>=0; i--) {
        B->inc(m[i], n-i);
        int t = m[i];
        int ans = B->psum(m[i]-1);
        if(ans == inff) ans = 0;
        ans = n-ans;
        afterturn[i] = 1ll*t*(ans-i);
        if(ans != n) afterturn[i] += afterturn[ans];
    }
    ll bes = -1; int optp = -1;
    rep(i, n) {
        ll k = beforeturn[i] - m[i] + afterturn[i];
        if(bes < k) {
            optp = i;
            bes = k;
        }
    }
    test(optp, 1);
    rep(i, n) {
        if(i) cout << ' ';
        cout << an[i];
    }
    cout << endl;
}