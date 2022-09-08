#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

bool get_bit(long long x, int pos) {
    return (bool) ((x >> pos) & 1);
}

const int S = sizeof(long long);

int n, p[max_n];
long long ans, k, x[2 * max_n], tmp[2 * max_n];
vector<int> l, r, pos;
vector<int> nl, nr, np;

long long get0(int l, int r, int pos, int bt) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = l; i < pos; ++i) {
        b += get_bit(x[i], bt);
    }
    for (int i = pos; i < r; ++i) {
        d += get_bit(x[i], bt);
    }
    a = pos - l - b;
    c = r - pos - d;
    return 1LL * a * c + 1LL * b * d;
}

int repos(int l, int r, int b, int val) {
    int id = l;
    for (int i = l; i < r; ++i) {
        if (get_bit(x[i], b) == val) {
            tmp[id++] = x[i];
        }
    }
    int res = id;
    for (int i = l; i < r; ++i) {
        if (get_bit(x[i], b) != val) {
            tmp[id++] = x[i];
        }
    }
    memcpy(x + l, tmp + l, S * (r - l));
    return res;
}

void add(int l, int p, int r) {
    if (l < p && p < r) {
        nl.push_back(l);
        np.push_back(p);
        nr.push_back(r);
    }
}

void regroup(int l, int r, int pos, int b, int val) {
    int id1 = repos(l, pos, b, 0);
    int id2 = repos(pos, r, b, val);
    //cout << id1 << " " << id2 << endl;
    memcpy(tmp + id1, x + pos, S * (id2 - pos));
    memcpy(tmp + id1 + id2 - pos, x + id1, S * (pos - id1));
    memcpy(x + id1, tmp + id1, S * (id2 - id1));
    add(l, id1, id1 + id2 - pos);
    add(id1 + id2 - pos, id2, r);
}

void regroup(int b, int val) {
    nl.clear();
    nr.clear();
    np.clear();
    for (int i = 0; i < l.size(); ++i) {
        regroup(l[i], r[i], pos[i], b, val);
    }
    l.swap(nl);
    r.swap(nr);
    pos.swap(np);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d", &n, &k);
    for (int i = 1; i < n; ++i) {
        scanf("%d%I64d", &p[i], &x[i]);
        --p[i];
        x[i] ^= x[p[i]];
    }
    for (int i = n; i < 2 * n; ++i) {
        x[i] = x[i - n];
    }
    l.push_back(0);
    r.push_back(2 * n);
    pos.push_back(n);
    for (int b = 61; b >= 0; --b) {
        long long zero = 0;
        for (int i = 0; i < l.size(); ++i) {
            zero += get0(l[i], r[i], pos[i], b);
        }
        if (zero >= k) {
            regroup(b, 0);
        } else {
            k -= zero;
            regroup(b, 1);
            ans += 1LL << b;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}