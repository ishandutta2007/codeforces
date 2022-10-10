#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

int n;
vi a;
void read() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

template<typename II> ve<II> nse(II b, II e) {
    ve<II> ans;
    ans.resize(distance(b, e));
    static stack<II> st;
    for (II i = b; i != e; ++i) {
        for (; st.size() and *st.top() > *i; st.pop())
            ans[distance(b, st.top())] = i;
        st.push(i);
    }
    for (; st.size(); st.pop()) ans[distance(b, st.top())] = e;
    return ans;
}

ve<vi::iterator> u;
ve<vi::reverse_iterator> v;
map<int, int> ma;
ve<ii> b;
void preprocess() {
    u = nse(a.bb, a.ee);
    v = nse(a.rbb, a.ree);
    reverse(v.bb, v.ee);
    for (int i = 0; i < n; ++i) {
        int x = u[i] - a.bb - 1, y = a.ree - v[i];
        int mr = x - y + 1;
        ma[a[i]] = max(ma[a[i]], mr);
    }
    for (map<int, int>::iterator it = ma.bb; it != ma.ee; ++it) {
        for (; sz(b) and b.back().yy < it->yy; b.pop_back());
        b.push_back(*it);
    }
}

vi ans;
void process() {
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = sz(b) - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (b[mid].yy >= i) l = mid;
            else r = mid - 1;
        }
        ans.push_back(b[l].xx);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    preprocess();
    process();
    for (int i = 0; i < sz(ans); ++i) printf("%d ", ans[i]);

    return 0;
}