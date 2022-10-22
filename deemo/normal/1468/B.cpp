#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 2e5 + 10;

struct Node {
    int min_avg_pos;
    ll min_avg_sum;
    int min_avg_count;
    ll sum;
    int count;
};

int n, a[MAXN];
Node seg[MAXN<<2];

ll cl(ll a, ll b) {
    return (a + b - 1) / b;
}

bool cmp(Node l, Node r) {
    r.min_avg_sum += l.sum;
    r.min_avg_count += l.count;
    return ld(l.min_avg_sum) / l.min_avg_count <= ld(r.min_avg_sum) / r.min_avg_count;
}

Node merge(Node l, Node r) {
    if (l.sum == -1) return r;
    if (r.sum == -1) return l;

    Node res;
    if (cmp(l, r)) { // l <= r
        res.min_avg_pos = l.min_avg_pos;
        res.min_avg_sum = l.min_avg_sum;
        res.min_avg_count = l.min_avg_count;
    } else {
        res.min_avg_pos = r.min_avg_pos;
        res.min_avg_sum = l.sum + r.min_avg_sum;
        res.min_avg_count = l.count + r.min_avg_count;
    }

    res.sum = l.sum + r.sum;
    res.count = l.count + r.count;
    return res;
}

void plant(int v, int b, int e) {
    if (e - b == 1) {
        seg[v].min_avg_pos = b;
        seg[v].min_avg_sum = a[b];
        seg[v].min_avg_count = 1;
        seg[v].sum = a[b];
        seg[v].count = 1;
        return;
    }

    int mid = b + e >> 1;
    plant(v<<1, b, mid);
    plant(v<<1^1, mid, e);
    seg[v] = merge(seg[v<<1], seg[v<<1^1]);
}

Node nl {-1, -1, -1, -1, -1};

pair<ll, int> get_min_avg(int v, int b, int e, int l, int r) {
    ld cur_min = a[l];
    int cur_pos = l;
    ll cur_sum = a[l];
    for (int i = l+1; i < r; i++) {
        cur_sum += a[i];
        if (ld(cur_sum) / (i-l + 1) < cur_min)
            cur_min = ld(cur_sum) / (i-l + 1), cur_pos = i;
    }
    return {1ll*ceil(cur_min), cur_pos};


   /* if (l <= b && e <= r) return seg[v];
    if (r <= b || e <= l) return nl;

    int mid = b + e >> 1;
    return merge(get_min_avg(v<<1, b, mid, l, r), get_min_avg(v<<1^1, mid, e, l, r));*/
}

pair<ll, pair<pii, int>> sec[MAXN]; int sz;
void go(int l, int r, ll prv = -1) {
    if (r - l <= 1) return;
    
    auto mn = get_min_avg(1, 0, n, l, r - 1);
    //ll cur = cl(mn.min_avg_sum, mn.min_avg_count);
    ll cur = mn.F;
    if (cur < prv) {
        cout << cur << "   " << prv << endl;
        assert(0);
    }
    // int mid = mn.min_avg_pos;
    int mid = mn.S;
    sec[sz++] = {cur, {{l, r}, mid}};

    go(l, mid + 1, cur);
    go(mid+1, r, cur);
}

pair<ll, int> ans[MAXN]; int tt;
int ln(pii s){
    return s.S - s.F;
}

bool cmp2(pair<ll, pair<pii, int>> a, pair<ll, pair<pii, int>> b) {
    if (a.F ^ b.F)
        return a.F < b.F;
    return ln(a.S.F) > ln(b.S.F);
}

void gen_ans() {
    sort(sec, sec + sz, cmp2);
    set<pair<int, pii>> st;
    st.insert({n, {0, n}});
    ans[tt++] = {0ll, n - 1};
    int cur = n-1;
    for (int i = 0; i < sz; i++) {
        ll val = sec[i].F;
        int tl = sec[i].S.F.F;
        int tr = sec[i].S.F.S;
        int p = sec[i].S.S;
        // assert(st.count({tr - tl, {tl, tr}}));
        st.erase({tr - tl, {tl, tr}});
        st.insert({p+1 - tl, {tl, p+1}});
        st.insert({tr-p-1, {p+1, tr}});
        //cout << st.size() << endl;
        
        cur = st.rbegin()->F - 1;
        if (tt && ans[tt-1].F == val)
            ans[tt-1] = {val, cur};
        else
            ans[tt++] = {val, cur};
    }
}

ll comp_sum[MAXN];
int comp_count[MAXN];

void go() {
    set<pair<ld, int>> st;
    for (int i = 0; i + 1 < n; i++)
        st.insert({(ld)a[i], i});
    set<int> remaining;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        remaining.insert(i);
        comp_sum[i] = a[i];
        comp_count[i] = 1;
    }
    ans[tt++] = {mx, 0};
    int cur_max = 0;
    while (st.size()) {
        auto x = st.rbegin()->S;
        ld val = st.rbegin()->F;
        st.erase(*st.rbegin());
        int y = *remaining.upper_bound(x);
        int ry = remaining.upper_bound(y) != remaining.end()? *remaining.upper_bound(y): -1;
        /*int lx = -1;
        {
            auto it = remaining.lower_bound(x);
            if (it != remaining.begin()) {
                it--;
                lx = *it;
            }
        }*/
        // if (ry != -1)
        st.erase({ld(comp_sum[y])/ comp_count[y], y});

        remaining.erase(y);
        comp_sum[x] += comp_sum[y];
        comp_count[x] += comp_count[y];
        if (ry != -1)
            st.insert({ld(comp_sum[x]) / comp_count[x], x});
        cur_max = max(cur_max, comp_count[x] - 1);
        ans[tt++] = {(ll)ceil(val), cur_max};
        //cout << x << " " << y << " " << tt << " " << ans[tt-1].F << " " << ans[tt-1].S << endl;
        if (tt >= 2)
            assert(ans[tt-1].F <= ans[tt-2].F);
    }
    ans[tt++] = {0, n-1};
    reverse(ans, ans + tt);
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    plant(1, 0, n);
    // go(0, n);
    go();
    // gen_ans();
    //cout << tt << endl;
    //for (int i = 0; i < tt; i++)
      //  cout << ans[i].F << "  " << ans[i].S << endl;
    while (q--) {
        ll k; cin >> k;
        int pos = lower_bound(ans, ans + tt, make_pair(k+1, -1)) - ans;
        cout << ans[pos].S << " ";
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}