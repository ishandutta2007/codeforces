#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_m = 1e5 + 100;
const int max_n = 2 * max_m;
const int modulo = 1e9 + 7;

struct segment {
    int start;
    int finish;
};

bool cmp_segment(const segment& a, const segment& b) {
    return a.finish < b.finish;
}

int t[4 * max_n];
int t_size;
int n, m;

segment s[max_m];
int p[max_n];

map<int, int> mp;

int get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r)
        return t[v];
    else {
        int m = (tl + tr) >> 1;
        if (r <= m)
            return get(2 * v, tl, m, l, r);
        else if (l > m)
            return get(2 * v + 1, m + 1, tr, l, r);
        else
            return (get(2 * v, tl, m, l, m) +
                    get(2 * v + 1, m + 1, tr, m + 1, r)) % modulo;
    }
}

int get(int l, int r) {
    return get(1, 0, t_size - 1, l, r);
}

void incr(int v, int tl, int tr, int x, int d) {
    if (tl == tr)
        t[v] = (t[v] + d) % modulo;
    else {
        t[v] = (t[v] + d) % modulo;
        int m = (tl + tr) >> 1;
        if (x <= m)
            incr(2 * v, tl, m, x, d);
        else if (x > m)
            incr(2 * v + 1, m + 1, tr, x, d);
    }
}

void incr(int x, int d) {
    incr(1, 0, t_size - 1, x, d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    p[0] = 0;
    p[1] = n;
    n = 2;
    for (int i = 0; i < m; ++i) {
        cin >> s[i].start >> s[i].finish;
        p[n] = s[i].start;
        p[n + 1] = s[i].finish;
        n += 2;
    }
    sort(p, p + n);
    int tn = 1;
    for (int i = 1; i < n; ++i)
        if (p[i] != p[tn - 1]) {
            p[tn] = p[i];
            ++tn;
        }
    n = tn;
    for (int i = 0; i < n; ++i)
        mp[p[i]] = i;
    for (int i = 0; i < m; ++i) {
        s[i].start = mp[s[i].start];
        s[i].finish = mp[s[i].finish];
    }
    sort(s, s + m, cmp_segment);
    t_size = n;
    incr(0, 1);
    for (int i = 0; i < m; ++i)
        incr(s[i].finish, get(s[i].start, s[i].finish - 1));
    cout << get(n - 1, n - 1) << endl;
    return 0;
}