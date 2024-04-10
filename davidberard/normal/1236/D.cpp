#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

set<int> in_row[N];
set<int> in_col[N];

/*
struct node {
    int count, ll, rr;
    node *left, *right;
    node() {}
    node(int a, int b, int c) : count(a), ll(b), rr(c), left(nullptr), right(nullptr) {}
    int query(int l, int r) {
        if (l >= rr || r <= ll) return 0;
        if (l <= ll && r >= rr) return count;
        assert (left != nullptr && right != nullptr);
        return left->query(l, r) + right->query(l, r);
    }
    void insert(int i, int x) {
        if (i < ll || i >= rr) return;
        count += x;
        if (rr-ll > 1) {
            if (left == nullptr) {
                int m = (ll+rr)/2;
                left = new node(0, ll, m);
                right = new node(0, m, rr);
            }
            left->insert(i, x);
            right->insert(i, x);
        }
    }
};

struct segtree {
    vector<node*> t;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<node*>(n*2);
        for (int i=0; i<n*2; ++i) {
            t[i] = new node(0, 0, n);
        }
    }
    void apply(int i, int x) {
        for (i += n; i; i/=2) {
            t[i]->insert(x, 1);
        }
    }
    void insert(int x, int y) {
        for (int i = y+n; i; i/=2) {
            t[i]->insert(x, 1);
        }
    }
    int query(int x1, int y1, int x2, int y2) {
        int ans = 0;
        int l = y1, r = y2;
        for (l += n, r += n; l<r; l/=2, r/=2) {
            if (l%2) {
                ans += t[l++].query(x1, x2);
            }
            if (r%2) {
                ans += t[--r].query(x1, x2);
            }
        }
        return ans;
    }
};
*/
int n, m, k;
int xh, xl, yh, yl, xd, yd, x, y;
ll taken = 0;


void eval() {
    //cerr << " taken " << taken << " need " << (ll)n*m - k << endl;
    if (taken == (ll)n*m - k) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    //segtree st(N);
    cin >> n >> m >> k;
    for (int i=0; i<k; ++i) {
        int x, y;
        cin >> x >> y;
        //st.insert(x, y);
        in_row[x].insert(y);
        in_col[y].insert(x);
    }
    xh = n+1;
    xl = 1;
    yh = m+1;
    yl = 0;

    xd = 0;
    yd = 1;

    x = 1;
    y = 0;

    for(int jj = 0; jj < n*5; jj++) {
        //cerr << " " << x << " " << y << endl;
        if (yd == 1) {
            //cerr << " yd = 1" << endl;
            auto p = in_row[x].upper_bound(y);
            int nyh = yh;
            if (p == in_row[x].end()) {
                nyh = yh;
            } else {
                nyh = *p;
            }
            nyh = min(nyh, yh);
            //cerr << " taking " << abs(y-(yh-1)) << endl;
            if (nyh < yl+2) {
                eval();
                return 0;
            }
            yh = nyh;
            taken += abs(y-(yh-1));
            y = yh-1;
            
            ++yl;
            xd = 1;
            yd = 0;
        } else if (yd == -1) {
            auto p = in_row[x].lower_bound(y);
            int nyl;
            if (p == in_row[x].begin()) {
                nyl = yl;
            } else {
                nyl = *prev(p) + 1;
            }

                nyl = max(nyl, yl);
                if (nyl > yh-2) {
                    eval();
                    return 0;
                }
                yl = nyl;
                taken += abs(y-yl);
                y = yl;

            --yh;
            xd = -1;
            yd = 0;
        } else if(xd == 1) {
            auto p = in_col[y].upper_bound(x);
            int nxh;
            if (p == in_col[y].end()) {
                nxh = xh;
            } else {
                nxh = *p;
            }

                nxh = min(nxh, xh);
                if (nxh < xl+2) {
                    eval();
                    return 0;
                }
                xh = nxh;
                taken += abs(x-(xh-1));
                x = xh-1;

            ++xl;
            xd = 0;
            yd = -1;
        } else if(xd == -1) {
            auto p = in_col[y].lower_bound(x);
            int nxl;
            if (p == in_col[y].begin()) {
                nxl = xl;
            } else {
                nxl = *prev(p) + 1;
            }

                nxl = max(nxl, xl);
                if (nxl > xh-2) {
                    eval();
                    return 0;
                }
                xl = nxl;
                taken += abs(x-xl);
                x = xl;

            --xh;
            xd = 0;
            yd = 1;
        }
    }
    assert(false);

    return 0;
}