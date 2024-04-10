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

const int max_n = 100111;

const int p1 = 31, mod1 = 1000000007;
const int p2 = 41, mod2 = 1000000123;
const char min_c = '?';

int n, ans, H1[2], H2[2];
string s, t;
int h1_h[2][max_n], h1_pw[2][max_n], Mod1[2];
int h2_h[2][max_n], h2_pw[2][max_n], Mod2[2];

    void Hash_1_0(string s, int p, int mod) {
        Mod1[0] = mod;
        h1_pw[0][0] = 1;
        for (int i = 1; i < max_n; ++i) {
            h1_pw[0][i] = (1LL * h1_pw[0][i - 1] * p) % mod;
        }
        h1_h[0][0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h1_h[0][i] = (1LL * p * h1_h[0][i - 1] + s[i] - min_c + 1) % mod;
        }
    }

    void Hash_1_1(string s, int p, int mod) {
        Mod1[1] = mod;
        h1_pw[1][0] = 1;
        for (int i = 1; i < max_n; ++i) {
            h1_pw[1][i] = (1LL * h1_pw[1][i - 1] * p) % mod;
        }
        h1_h[1][0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h1_h[1][i] = (1LL * p * h1_h[1][i - 1] + s[i] - min_c + 1) % mod;
        }
    }

    void Hash_2_0(string s, int p, int mod) {
        Mod2[0] = mod;
        h2_pw[0][0] = 1;
        for (int i = 1; i < max_n; ++i) {
            h2_pw[0][i] = (1LL * h2_pw[0][i - 1] * p) % mod;
        }
        h2_h[0][0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h2_h[0][i] = (1LL * p * h2_h[0][i - 1] + s[i] - min_c + 1) % mod;
        }
    }

    void Hash_2_1(string s, int p, int mod) {
        Mod2[1] = mod;
        h2_pw[1][0] = 1;
        for (int i = 1; i < max_n; ++i) {
            h2_pw[1][i] = (1LL * h2_pw[1][i - 1] * p) % mod;
        }
        h2_h[1][0] = s[0] - min_c + 1;
        for (int i = 1; i < s.length(); ++i) {
            h2_h[1][i] = (1LL * p * h2_h[1][i - 1] + s[i] - min_c + 1) % mod;
        }
    }

    int get_hash_1_0(int l, int r) {
        if (l > r) {
            return 0;
        }
        int x = h1_h[0][r], y = 0;
        if (l != 0) {
            y = (1LL * h1_h[0][l - 1] * h1_pw[0][r - l + 1]) % Mod1[0];
        }
        int res = x - y + Mod1[0];
        while (res >= Mod1[0]) {
            res -= Mod1[0];
        }
        while (res < 0) {
            res += Mod1[0];
        }
        return res;
    }

    int get_hash_1_1(int l, int r) {
        if (l > r) {
            return 0;
        }
        int x = h1_h[1][r], y = 0;
        if (l != 0) {
            y = (1LL * h1_h[1][l - 1] * h1_pw[1][r - l + 1]) % Mod1[1];
        }
        int res = x - y + Mod1[1];
        while (res >= Mod1[1]) {
            res -= Mod1[1];
        }
        while (res < 0) {
            res += Mod1[1];
        }
        return res;
    }

    int get_hash_2_0(int l, int r) {
        if (l > r) {
            return 0;
        }
        int x = h2_h[0][r], y = 0;
        if (l != 0) {
            y = (1LL * h2_h[0][l - 1] * h2_pw[0][r - l + 1]) % Mod2[0];
        }
        int res = x - y + Mod2[0];
        while (res >= Mod2[0]) {
            res -= Mod2[0];
        }
        while (res < 0) {
            res += Mod2[0];
        }
        return res;
    }

    int get_hash_2_1(int l, int r) {
        if (l > r) {
            return 0;
        }
        int x = h2_h[1][r], y = 0;
        if (l != 0) {
            y = (1LL * h2_h[1][l - 1] * h2_pw[1][r - l + 1]) % Mod2[1];
        }
        int res = x - y + Mod2[1];
        while (res >= Mod2[1]) {
            res -= Mod2[1];
        }
        while (res < 0) {
            res += Mod2[1];
        }
        return res;
    }

int get_hash(int i, int l, int r, char c, int num, int mod) {
    if (r < i) {
        if(num == 1) return get_hash_1_1(l, r); else return get_hash_1_0(l, r);
    }
    if (l > i) {
        if(num == 1) return get_hash_1_1(l-1, r-1); else return get_hash_1_0(l-1, r-1);
    }
    if(num == 1)
        return (1LL * (1LL * get_hash_1_1(l, i - 1) * h1_pw[1][1] % mod + c - min_c + 1) * h1_pw[1][r - i] + get_hash_1_1(i, r - 1)) % mod;
        return (1LL * (1LL * get_hash_1_0(l, i - 1) * h1_pw[0][1] % mod + c - min_c + 1) * h1_pw[0][r - i] + get_hash_1_0(i, r - 1)) % mod;
}

bool ok(int i, int poz, char c) {
    H2[0] = get_hash_2_0(0, poz);
    H1[0] = get_hash(i, 0, poz, c, 0, mod1);
    if (H1[0] != H2[0]) {
        return false;
    }
    H2[1] = get_hash_2_1(0, poz);
    H1[1] = get_hash(i, 0, poz, c, 1, mod2);
    //cout << H1[0] << " " << H2[0] << endl;
    //cout << H1[1] << " " << H2[1] << endl;
    return H1[1] == H2[1];
}

vector<pair<int, int> > qq;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s >> t;
    t += '?';
    Hash_1_0(s, p1, mod1);
    Hash_1_1(s, p2, mod2);
    Hash_2_0(t, p1, mod1);
    Hash_2_1(t, p2, mod2);
    int q = get_hash_2_0(0, n - 1);
    int w = get_hash_2_1(0, n - 1);
    //cout << ok(1, 1, 'r') << endl;
    //return 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i + j < 0 || i + j >= n) continue;
            char c = t[i + j];
            int l = -1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (ok(i, mid, c)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            H1[0] = (1LL * get_hash(i, 0, r - 1, c, 0, mod1) * h1_pw[0][n - r] + get_hash(i, r + 1, n, c, 0, mod1)) % mod1;
            H1[1] = (1LL * get_hash(i, 0, r - 1, c, 1, mod2) * h1_pw[1][n - r] + get_hash(i, r + 1, n, c, 1, mod2)) % mod2;
            /*if (i == 1 && c == 'r') {
                cout << r << endl;
                cout << H1[0] << " " << q << endl;
                cout << H1[1] << " " << w << endl;
            }*/
            int gg1 = get_hash(i, 0, n, c, 0, mod1);
            int gg2 = get_hash(i, 0, n, c, 1, mod2);
            if (H1[0] == q && H1[1] == w) {
                qq.push_back(make_pair(gg1, gg2));
                //cout << i << " " << c << endl;
                break;
            }
        }
    }
    sort(qq.begin(), qq.end());
    qq.erase(unique(qq.begin(), qq.end()), qq.end());
    cout << qq.size() << endl;
    return 0;
}