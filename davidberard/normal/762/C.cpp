#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

string a, b;
int pre[N], suf[N];

struct res {
    int sz, i, j;
    res() {}
    res(int a, int b, int c) : sz(a), i(b), j(c) {}
    bool operator < (const res& o) const {
        return sz < o.sz;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    int j=0;
    for (int i=0; i<b.size(); ++i) {
        while (j<a.size() && a[j] != b[i]) {
            ++j;
        }
        pre[i] = j;
        ++j;
    }
    j = a.size()-1;
    for (int i=b.size()-1; i>=0; --i) {
        while (j>=0 && a[j] != b[i]) {
            --j;
        }
        suf[i] = j;
        --j;
    }
    suf[b.size()] = a.size()+1;

    res best(1e9, -1, -1);
    for (int i=0; i<b.size(); ++i) {
        //cerr << "! i = " << i << endl;
        int q = -1;
        if (i > 0) {
            q = pre[i-1];
        }
        if (q >= (int) a.size()) continue;
        int lo = i;
        int hi = b.size();
        while (lo < hi) {
            int m = (lo+hi)/2;

            if (suf[m] <= q) {
                lo = m+1;
            } else {
                hi = m;
            }
        }
        //cerr << "! " << i << " " << q << " " << lo << endl;
        res tv(lo-i, i, lo);
        best = min(best, tv);
    }

    if (pre[b.size()-1] < a.size()) {
        best = min(best, res(0, a.size(), a.size()));
    }

    //cerr << "! " << best.sz << " " << best.i << " " << best.j << endl;

    if (best.sz >= b.size()) {
        cout << "-\n";
        return 0;
    }

    for (int i=0; i<best.i; ++i) {
        cout << b[i];
    }
    for (int i=best.j; i<b.size(); ++i) {
        cout << b[i];
    }
    cout << endl;

    return 0;
}