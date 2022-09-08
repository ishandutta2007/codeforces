#include <ctime>
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

const int max_n = 101111, max_len = 1000111, inf = 1111111111;
int p1, p2, mod;

int n, k, m, pw1[max_len], h1[max_len];
long long pw2[max_len], h2[max_len];
char a[max_len];
string s;
map<pair<int, long long>, int> q;
set<pair<int, long long> > qq;
pair<int, long long> p[max_n];

pair<int, long long> get(const string &s) {
    int h1 = 0;
    long long h2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        h1 = (1LL * h1 * p1 + s[i] - 'a' + 1) % mod;
        h2 = h2 * p2 + s[i] - 'a' + 1;
    }
    return make_pair(h1, h2);
}

void proc() {
    p1 = next_prime(100 + rand() % 200);
    p2 = next_prime(100 + rand() % 200);
    mod = next_prime(1000000000 + rand() % 10000);
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < max_len; ++i) {
        pw1[i] = (1LL * pw1[i - 1] * p1) % mod;
        pw2[i] = pw2[i - 1] * p2;
    }
    h1[0] = s[0] - 'a' + 1;
    h2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); ++i) {
        h1[i] = (1LL * h1[i - 1] * p1 + s[i] - 'a' + 1) % mod;
        h2[i] = h2[i - 1] * p2 + s[i] - 'a' + 1;
    }
}

int get_h1(int l, int r) {
    int x = h1[r], y = 0;
    if (l) {
        y = (1LL * h1[l - 1] * pw1[r - l + 1]) % mod;
        //cout << "!" << x << " " << y << "   " << l << " " << r << " " << h1[l - 1] << " " << pw1[r - l + 1] << endl;
    }
    return (x - y + mod) % mod;

}

long long get_h2(int l, int r) {
    if (l == 0) {
        return h2[r];
    }
    return h2[r] - h2[l - 1] * pw2[r - l + 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, a);
    s = a;
    proc();
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", a);
        pair<int, long long> p = get(a);
        if (q.count(p)) {
            return 228;
        }
        q[p] = i;
    }
    for (int i = 0; i < k; ++i) {
        int f = 1;
        qq.clear();
        for (int j = 0; j < n; ++j) {
            int l = i + k * j, r = i + k * (j + 1) - 1;
            if (j + 1 < n || i == 0) {
                p[j].first = get_h1(l, r);
                p[j].second = get_h2(l, r);
            } else {
                p[j].first = (1LL * get_h1(l, s.length() - 1) * pw1[i] + h1[i - 1]) % mod;
                p[j].second = get_h2(l, s.length() - 1) * pw2[i] + h2[i - 1];
            }
            //if (i) cout << p[j].first << " " << p[j].second << " [" << l << " " << r << "]" << endl;
            if (!q.count(p[j])) {
                f = 0;
                break;
            }
            if (qq.count(p[j])) {
                f = 0;
                break;
            }
            qq.insert(p[j]);
        }
        if (f) {
            printf("YES\n");
            for (int i = 0; i < n; ++i) {
                printf("%d ", 1 + q[p[i]]);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}