#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sign(a) ((a < 0) ? -1 : (a > 0))

typedef pair<long, int> li;
int n, k, x;
ve<long> a;
void read() {
    cin >> n >> k >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
}

priority_queue<li> pq;

void process() {
    int si = 1;
    vi zero;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) zero.push_back(i);
        else si *= sign(a[i]);
    }

    for (; zero.size() > 1 and k > 0; zero.pop_back()) {
        a[zero.back()] = x;
        --k;
    }

    if (!k) return;

    if (si >= 0) {
        if (zero.size()) {a[zero.back()] = -x; --k; zero.pop_back();}
        else {
            li mp = li(lim<int>::max() - 1, -1), mn = li(lim<int>::min() + 1, -1);
            for (int i = 0; i < n; ++i) {
                if (a[i] >= 0) mp = min(mp, li(a[i], i));
                else mn = max(mn, li(a[i], i));
            }
            if (abs(mp.xx) > abs(mn.xx)) mp = mn;
            int s = sign(mp.xx);
            while (k and s * sign(a[mp.yy]) >= 0) {
                --k;
                a[mp.yy] -= s * x;
            }
        }
    }
    if (!k) return;
    if (zero.size()) {a[zero.back()] = x; --k;}

    for (int i = 0; i < n; ++i) {
        pq.push(li(-abs(a[i]), i));
    }

    for (int i = 0; i < k; ++i) {
        ii t = pq.top(); pq.pop();
        a[t.yy] += sign(a[t.yy]) * x;
        pq.push(li(-abs(a[t.yy]), t.yy));
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);

    read();
    process();
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';

    return 0;
}