#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_v = 2000111, inf = 1000111222;

template<typename T>
class FastAdder {
public:
    FastAdder(int from, int to): from(from), d(to - from + 3), prepared(false) {
    }

    void clear() {
        prepared = false;
        fill(d.begin(), d.end(), T(0));
    }

    // a[i] += k (l <= i <= r)
    void add_constant(int l, int r, T k) {
        if (l > r) {
            return;
        }
        l -= from;
        r -= from;
        assert(!prepared);
        assert(0 <= l && r + 2 < d.size());
        d[l] += k;
        d[l + 1] -= k;
        d[r + 1] -= k;
        d[r + 2] += k;
    }

    // a[l] += k, a[l + 1] += 2k, ... (l <= i <= r)
    void add_progression(int l, int r, T k) {
        if (l > r) {
            return;
        }
        l -= from;
        r -= from;
        assert(!prepared);
        assert(0 <= l && r + 2 < d.size());
        d[l] += k;
        d[r + 1] -= T(r - l + 2) * k;
        d[r + 2] += T(r - l + 1) * k;
    }

    // a[r] += k, a[r - 1] += 2k, ... (l <= i <= r)
    void add_reversed_progression(int l, int r, T k) {
        add_progression(l, r, -k);
        add_constant(l, r, T(r - l + 2) * k);
    }

    void prepare() {
        assert(!prepared);
        prepared = true;
        for (int it = 0; it < 2; ++it) {
            for (int i = 1; i < d.size(); ++i) {
                d[i] += d[i - 1];
            }
        }
    }

    T get_value(int pos) const {
        pos -= from;
        assert(prepared);
        assert(0 <= pos && pos + 2 < d.size());
        return d[pos];
    }

private:
    vector<T> d;
    int from;
    bool prepared;
};

ll a[max_n];
ll b[max_n];
ll m[max_n];
ll d[max_n];
ll sum[max_n];
int n, q;
bool debug = 0;
FastAdder<long long> adder(0, max_v);

void add_oleg(int l, int r, long long k, long long b) {
    adder.add_constant(l, r, b);
    adder.add_progression(l + 1, r, k);
}

void proc(ll base, ll d) {
    //ans[i] += abs(base + d * i);
    //cout << "$$ " << base << ' ' << d << endl;
    if (base < 0) {
        base *= -1;
        d *= -1;
    }
    if (d >= 0) {
        add_oleg(0, max_v - 2, d, base);
    } else {
        int k = base / abs(d);
        add_oleg(0, min(max_v - 3, k), d, base);
        int st = abs(base % d - d);
        if (k + 1 < max_v - 3) {
            add_oleg(k + 1, max_v - 3, abs(d), st);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i <= n; ++i) {
        sum[i] = 1;
    }
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i] = -sum[i];
        for (int j = i; j <= n; j += i) {
            sum[j] += d[i];
        }
    }
    cin >> q;
    int mn = 1e8;
    vector<int> v;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        v.PB(x);
        mn = min(mn, x);
    }
    //sort(v.begin(), v.end());
    b[1] = mn;

    for (int i = 1; i <= n; ++i) {
        //cout << "$$ " << b[i] << ' ' << a[i] << endl;
        m[i] = b[i] - a[i];
        for (int j = i; j <= n; j += i) {
            a[j] += m[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        d[i] = d[i + 1];
        if (debug) cout << d[i] << ' ';
    }
    if (debug) cout << endl;
    for (int i = 0; i < n; ++i) {
        m[i] = m[i + 1];
        if (debug) cout << m[i] << ' ';
    }
    if (debug) cout << endl;
    for (int i = 0; i < n; ++i) {
        proc(m[i], d[i]);
    }
    adder.prepare();
    for (int x : v) {
        cout << adder.get_value(x - mn) << "\n";
    }
    return 0;
}