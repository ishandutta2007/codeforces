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

const int max_n = 202222, max_c = 26;
int p1, p2;
int mod;

int n, m;
char s[max_n], a[max_c][max_n];
int h1[max_c][max_n], pw1[max_n], nxt[max_c][max_n];
long long h2[max_c][max_n], pw2[max_n];

void prec() {
    p1 = next_prime(rand() % 100 + 100);
    p2 = next_prime(rand() % 100 + 100);
    mod = next_prime(rand() % 10000 + 1000000000);
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw1[i] = (1LL * pw1[i - 1] * p1) % mod;
        pw2[i] = pw2[i - 1] * p2;
    }
}

void calc(int h1[], long long h2[], char a[]) {
    h1[0] = a[0];
    h2[0] = a[0];
    for (int i = 1; i < n; ++i) {
        h1[i] = (1LL * h1[i - 1] * p1 + a[i]) % mod;
        h2[i] = h2[i - 1] * p2 + a[i];
    }
}

int get_hash1(int c, int l, int r) {
    int res = h1[c][r];
    if (l) {
        res -= (1LL * h1[c][l - 1] * pw1[r - l + 1]) % mod;
        if (res < 0) {
            res += mod;
        }
    }
    return res;
}

long long get_hash2(int c, int l, int r) {
    long long res = h2[c][r];
    if (l) {
        res -= h2[c][l - 1] * pw2[r - l + 1];
    }
    return res;
}

pair<int, long long> get_hash(int c, int l, int r) {
    return {get_hash1(c, l, r), get_hash2(c, l, r)};
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));
    prec();
    scanf("%d%d%s", &n, &m, s);
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < n; ++i) {
            a[c - 'a'][i] = (s[i] == c) + 1;
        }
        calc(h1[c - 'a'], h2[c - 'a'], a[c - 'a']);
    }
    memset(nxt, -1, sizeof(nxt));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < max_c; ++j) {
            nxt[j][i] = nxt[j][i + 1];
        }
        nxt[s[i] - 'a'][i] = i;
    }
    while (m--) {
        int x, y, len;
        scanf("%d%d%d", &x, &y, &len);
        --x;
        --y;
        bool ok = true;
        for (int c = 0; c < max_c; ++c) {
            int pos = nxt[c][x];
            if (pos != -1 && pos < x + len) {
                int c2 = s[y + pos - x] - 'a';
                if (get_hash(c, x, x + len - 1) != get_hash(c2, y, y + len - 1)) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}