#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

const int max_lev = 18;
const int sz = 333, p = 424742 + 2 * (generator() % 100000) + 1;

string dp[max_n];
int n, start[max_n], nxt[max_n], nxt_sz[max_n], len[max_n];
int nx[max_n][max_lev];
string s;
long long h[max_n];

bool cmp_triv(int a, int b) {
    while (a < n && b < n) {
        if (s[a] != s[b]) {
            return s[a] < s[b];
        }
        a = nxt[a];
        b = nxt[b];
    }
    return a > b;
}

bool cmp(int a, int b) {
    while (len[a] >= sz && len[b] >= sz) {
        if (h[a] != h[b]) {
            break;
        }
        a = nxt_sz[a];
        b = nxt_sz[b];
    }
    return cmp_triv(a, b);
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

char get_nxt(int a, int pos) {
    for (int i = 0; i < max_lev; ++i) {
        if (get_bit(pos, i)) {
            a = nx[a][i];
        }
    }
    return s[a];
}

void calc_nx(int pos) {
    nx[pos][0] = nxt[pos];
    for (int lev = 1; lev < max_lev; ++lev) {
        nx[pos][lev] = nx[nx[pos][lev - 1]][lev - 1];
    }
    if (len[pos] >= sz) {
        long long pw = 1;
        int cur = pos;
        h[pos] = 0;
        for (int i = 0; i < sz; ++i) {
            h[pos] += pw * s[cur];
            cur = nxt[cur];
            pw *= p;
        }
        nxt_sz[pos] = cur;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 100000;
        for (int i = 0; i < n; ++i) {
            s += "abcd"[i % 4];
        }
    } else {
        s = read();
        n = s.length();
    }
    start[n] = n;
    nxt[n] = n;
    calc_nx(n);
    for (int i = n - 1; i >= 0; --i) {
        start[i] = i;
        nxt[i] = start[i + 1];
        len[i] = 1 + len[nxt[i]];
        calc_nx(i);
        if (i + 1 < n && s[i] == s[i + 1] && cmp(start[i + 2], i)) {
            start[i] = start[i + 2];
            len[i] = len[start[i]];
        }
        if (start[i] == i) {
            calc_nx(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", len[i]);
        string ans;
        if (len[i] <= 10) {
            for (int j = 0; j < len[i]; ++j) {
                ans += get_nxt(start[i], j);
            }
        } else {
            for (int j = 0; j < 5; ++j) {
                ans += get_nxt(start[i], j);
            }
            ans += "...";
            for (int j = 0; j < 2; ++j) {
                ans += get_nxt(start[i], len[i] - 2 + j);
            }
        }
        puts(ans.c_str());
    }
    return 0;
}