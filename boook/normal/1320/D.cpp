#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define F first
#define S second
#define int long long
#define mid (l + r >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)
#define AC 7902131ll
//#define mod 1000000000000091

const int N = 200006;
int a[N];
int pre1[N];
 
int Q1(int l, int r) {
    return pre1[r] - pre1[l - 1];
}

struct Node {
    int siz, val, vl, vr;
} st[N * 4];

int n, ps[N];
Node Pull(Node v1, Node v2) {
    Node ans;
    ans.vl = v1.vl;
    ans.vr = v2.vr;
    ans.siz = v1.siz + v2.siz - 1;

    if (v1.siz == 1) ans.vl = (v1.vr ^ v2.vl);
    if (v2.siz == 1) ans.vr = (v1.vr ^ v2.vl);
    if (v1.vr == 1 && v2.vl == 1)
        v1.val = (v1.val - 2);
    ans.val = (v1.val * ps[v2.siz - 1] + v2.val);
    return ans;
}

void Build(int now, int l, int r) {
    if (l == r) {
        if (a[l] == 0) st[now].siz = 2, st[now].val = 0, st[now].vl = 0, st[now].vr = 0;
        if (a[r] == 1) st[now].siz = 1, st[now].val = 1, st[now].vl = 1, st[now].vr = 1;
    }
    else {
        Build(ls, l, mid + 0);
        Build(rs, mid + 1, r);
        st[now] = Pull(st[ls], st[rs]);
    }
}

Node Query(int now, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return st[now];
    else if (qr <= mid + 0) return Query(ls, l, mid + 0, ql, qr);
    else if (mid + 1 <= ql) return Query(rs, mid + 1, r, ql, qr);
    return Pull(Query(ls, l, mid + 0, ql, qr), Query(rs, mid + 1, r, ql, qr));
}

pii go(int l, int r) {
//    cout << l << " " << r << " : " << Query(1, 1, n, l, r).val << endl;
    return make_pair(Q1(l, r), Query(1, 1, n, l, r).val);
}
 
int32_t main () {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ps[0] = 1;
    for (int i = 1; i < N; ++ i)
        ps[i] = ps[i - 1] * AC;

    cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i - 1] - '0';
        pre1[i] = pre1[i - 1] + a[i];
    }

    Build(1, 1, n);
    
    int q; cin >> q;
    while (q--) {
        int l1, l2, len; cin >> l1 >> l2 >> len;
        if (go(l1, len + l1 - 1) == go(l2, len + l2 - 1)) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
}