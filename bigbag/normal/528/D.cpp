#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 200002, inf = 1111111111;

struct my_bitset {
    vector<unsigned int> v;
    my_bitset operator & (const my_bitset &b) const {
        my_bitset res;
        res.v.resize(min(v.size(), b.v.size()));
        for (int i = 0; i < res.v.size(); ++i) {
            res.v[i] = v[i] & b.v[b.v.size() - i - 1];
        }
        return res;
    }
    bool operator == (const my_bitset &b) const {
        int sz = min(v.size(), b.v.size());
        for (int i = 0; i < sz; ++i) {
            if (v[i] != b.v[i]) {
                return false;
            }
        }
        return true;
    }
    void proc() {
        if (v.size() == 0) {
            return;
        }
        v.back() >>= 1;
        if (v.size() == 1) {
            return;
        }
        for (int i = v.size() - 2; i >= 0; --i) {
            if (v[i] % 2 == 1) {
                v[i + 1] |= (1LL << 31);
            }
            v[i] >>= 1;
        }
    }
    void fill(int poz, int f) {
        if (f == 1) {
            v[v.size() - 1 - (poz / 32)] |= (1LL << (poz % 32));
        }
    }
};

int n, m, k, a[2][max_n], cnt[max_n];
string s, t;
my_bitset b[2][4], bb[32];
vector<int> pozs[4];
vector<pair<int, int> > v[4];

int get_c(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
}

bool ok(int c, int num) {
    int sz = min(b[1][c].v.size(), b[0][c].v.size());
    int o = num % 32;
    int ts = num / 32;
    for (int i = 0; i < sz; ++i) {
        if ((b[1][c].v[b[1][c].v.size() - 1 - i] & bb[o].v[bb[o].v.size() - i - ts - 1]) != b[1][c].v[b[1][c].v.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void read() {
    n = 200000;
    m = 100000;
    k = 100000;
    for (int i = 0; i < n; ++i) {
        int x = rand() % 4;
        if (x == 0) s += 'A';
        if (x == 1) s += 'T';
        if (x == 2) s += 'G';
        if (x == 3) s += 'C';
    }
    for (int i = 0; i < n; ++i) {
        int x = rand() % 4;
        if (x == 0) t += 'A';
        if (x == 1) t += 'T';
        if (x == 2) t += 'G';
        if (x == 3) t += 'C';
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //read();
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < n; ++i) {
        a[0][i] = get_c(s[i]);
    }
    for (int i = 0; i < m; ++i) {
        a[1][i] = get_c(t[i]);
    }
    for (int c = 0; c < 4; ++c) {
        for (int i = 0; i < n; ++i) {
            if (a[0][i] == c) {
                v[c].push_back(make_pair(max(i - k, 0), 0));
                v[c].push_back(make_pair(min(i + k, n - 1), 1));
            }
        }
        sort(v[c].begin(), v[c].end());
        int y = 0, sz = 0;
        b[0][c].v.resize(n / 32 + 1);
        for (int i = 0; i < n; ++i) {
            int f = 0;
            if (y == v[c].size()) {
                continue;
            }
            if (v[c][y].first == i) {
                if (v[c][y].second == 0) {
                    ++sz;
                    ++y;
                }
            }
            if (sz > 0) {
                f = 1;
            }
            b[0][c].fill(i, f);
            while (y < v[c].size() && v[c][y].first == i) {
                if (v[c][y].second == 0) {
                    ++sz;
                } else {
                    --sz;
                }
                ++y;
            }
        }
        b[1][c].v.resize(m / 32 + 1);
        for (int i = 0; i < m; ++i) {
            if (a[1][i] == c) {
                b[1][c].fill(i, 1);
            }
        }
        //b[1][c].write();
        for (int i = 0; i + m - 1 < n; ++i) {
            if (i < 32) {
                bb[i] = b[0][c];
            }
            if (ok(c, i)) {
                ++cnt[i];
                //cout << i << " ";
            }
            if (i < 32) {
                b[0][c].proc();
            }
        }
        //cout << endl;
        //cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 4) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}