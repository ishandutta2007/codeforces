#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int x) {
    for (int i = x + 1; ; ++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

int p, p2, mod;

template <size_t N, char min_c>
struct Hash {
    long long h[N], pw[N];
    int h2[N], pw2[N];
    Hash() {
    }
    Hash(string s) {
        pw[0] = 1;
        for (int i = 1; i < N; ++i) {
            pw[i] = pw[i - 1] * p;
        }
        h[0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h[i] = p * h[i - 1] + s[i] - min_c + 1;
        }
        pw2[0] = 1;
        for (int i = 1; i < N; ++i) {
            pw2[i] = (1LL * pw2[i - 1] * p2) % mod;
        }
        h2[0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h2[i] = (1LL * p2 * h2[i - 1] + s[i] - min_c + 1) % mod;
        }
    }
    void operator = (const string &s) {
        *this = Hash(s);
    }
    pair<long long, int> get_hash(int l, int r) {
        if (l > r) {
            return make_pair(0LL, 0);
        }
        long long x = h[r], y = 0;
        if (l != 0) {
            y = h[l - 1] * pw[r - l + 1];
        }
        int xx = h2[r], yy = 0;
        if (l != 0) {
            yy = (1LL * h2[l - 1] * pw2[r - l + 1]) % mod;
        }
        return make_pair(x - y, (xx - yy + mod) % mod);
    }
};


const int max_n = 111111, inf = 1011111111;

int n;
string s[2];
Hash<max_n, 'a'> h[2];
int q, a[max_n], b[max_n];

void read() {
    char a[max_n];
    for (int i = 0; i < 2; ++i) {
        scanf("%s", a);
        s[i] = a;
        h[i] = s[i];
    }
}

void proc(char &c1, char &c2, int tp1, int l1, int r1, int tp2, int l2, int r2) {
    int l = -1, r = r1 - l1 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (h[tp1].get_hash(l1, l1 + mid) != h[tp2].get_hash(l2, l2 + mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    c1 = s[tp1][r];
    c2 = s[tp2][r];
}

char getc(int a, int pos) {
    if (pos < a) {
        return s[0][pos];
    }
    pos -= a;
    if (pos < s[1].length()) {
        return s[1][pos];
    }
    pos -= s[1].length();
    return s[0][a + pos];
}

pair<long long, int> get(int a, int pos) {
    if (pos < a) {
        return h[0].get_hash(0, pos);
    }
    pos -= a;
    if (pos < s[1].length()) {
        pair<long long, int> res = h[0].get_hash(0, a - 1);
        res.first *= h[0].pw[pos + 1];
        res.second = (1LL * res.second * h[0].pw2[pos + 1]) % mod;

        pair<long long, int> p = h[1].get_hash(0, pos);
        res.first += p.first;
        res.second = (1LL * res.second + p.second) % mod;
        return res;
    }
    pair<long long, int> res = h[0].get_hash(0, a - 1);
    res.first *= h[0].pw[pos + 1];
    res.second = (1LL * res.second * h[0].pw2[pos + 1]) % mod;

    pair<long long, int> p = h[1].get_hash(0, s[1].length() - 1);
    pos -= s[1].length();
    p.first *= h[0].pw[pos + 1];
    p.second = (1LL * p.second * h[0].pw2[pos + 1]) % mod;
    res.first += p.first;
    res.second = (1LL * res.second + p.second) % mod;

    p = h[0].get_hash(a, a + pos);
    res.first += p.first;
    res.second = (1LL * res.second + p.second) % mod;
    return res;
}

bool cmp(int a, int b) {
    int l = min(a, b) - 1, r = s[0].length() + s[1].length();
    if (get(a, r) == get(b, r)) {
        return a < b;
    }
    for (int i = min(a, b); ; ++i) {
        if (getc(a, i) != getc(b, i)) {
            return getc(a, i) < getc(b, i);
        }
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        //cout << mid << endl;
        if (get(a, mid) == get(b, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r == s[0].length() + s[1].length()) {
        //cout << "%" << a << " " << b<< endl;
        return a < b;
    }
    return getc(a, r) < getc(b, r);
}

void init() {
    srand(time(NULL));
    p = next_prime(100 + rand() % 200);
    p2 = next_prime(100 + rand() % 200);
    mod = next_prime(1000000000 + rand() % 1000);
}

const int sz = 100, max_lev = 17;

int num[max_n];

void get_all_num() {
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

struct sparse_table {
    vector<pair<int, int> > mins[max_lev];
    void get_all_mins(int n, pair<int, int> a[]) {
        for (int i = 0; i < max_lev; ++i) {
            mins[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            mins[0].push_back(a[i]);
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j < n && j + (1 << i) <= n; ++j) {
                mins[i].push_back(min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]));
            }
        }
    }
    pair<int, int> get_min(int l, int r) {
        if (l > r) {
            return make_pair(inf, 0);
        }
        int lev = num[r - l + 1];
        return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
    }
};

struct querry {
    int k, l, r, x, y, num;
    querry() {
    }
    void read(int i) {
        num = i;
        scanf("%d%d%d%d%d", &l, &r, &k, &x, &y);
    }
    bool operator < (const querry &q) const {
        return k < q.k;
    }
};

sparse_table sp[sz];
querry all[max_n];
pair<int, int> mn[max_n];
int ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    read();
    n = s[0].length() + 1;
    for (int i = 0; i < n; ++i) {
        b[i] = i;
    }
    sort(b, b + n, cmp);
    for (int i = 0; i < n; ++i) {
        a[b[i]] = i;
    }
    get_all_num();
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        all[i].read(i);
    }
    sort(all, all + q);
    int last = -1;
    for (int i = 0; i < q; ++i) {
        pair<int, int> res = make_pair(inf, 0);
        int x = all[i].x, y = all[i].y, l = all[i].l, r = all[i].r, k = all[i].k;
        if (k < sz) {
            if (last != k) {
                last = k;
                for (int j = 0; j < last; ++j) {
                    int cnt = 0;
                    for (int k = j; k < n; k += last) {
                        mn[cnt] = make_pair(a[k], k);
                        ++cnt;
                    }
                    sp[j].get_all_mins(cnt, mn);
                }
            }
            for (int j = x; j <= y; ++j) {
                if (j <= r) {
                    //cout << all[i].num << "#" << j << " " << (l - j + k - 1) / k << " " << (r - j) / k << endl;
                    res = min(res, sp[j].get_min((l - j + k - 1) / k, (r - j) / k));
                }
            }
        } else {
            if (last < sz) {
                last = sz;
                for (int j = 0; j < n; ++j) {
                    mn[j] = make_pair(a[j], j);
                }
                sp[0].get_all_mins(n, mn);
            }
            for (int j = 0; j + x < n; j += k) {
                res = min(res, sp[0].get_min(max(l, j + x), min(j + y, r)));
            }
        }
        if (res.first == inf) {
            res.second = -1;
        }
        ans[all[i].num] = res.second;
    }
    for (int i = 0; i < q; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}