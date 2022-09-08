#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, mod = 998244353;

int LEN;
int n, ans, sd, a[2][max_n], used[max_n];
string s;
vector<int> v;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int rev(int tp, int pos) {
    if (tp == 1) {
        return n - pos - 1;
    }
    return n - 1 - (pos + LEN - n);
}

bool dfs(int tp, int pos, int x) {
    v.push_back(pos);
    if (tp == 0 && pos < sd) {
        if (x == 0) {
            return true;
        }
        return false;
    }
    if (tp == 0 && pos == sd && a[tp][pos] == 0) {
        return false;
    }
    //cout << "#" << tp << " " << pos << " " << x << ", " << a[tp][pos] << endl;
    if (a[tp][pos] != -1) {
        if (a[tp][pos] != x && a[tp][pos] != 3) {
            return false;
        }
        return true;
    }
    a[tp][pos] = x;
    //cout << tp << " " << pos << " " << x << " -> " << tp << " " << rev(tp, pos) << " " << x << endl;
    if (!dfs(tp, rev(tp, pos), x)) {
        return false;
    }
    //cout << tp << " " << pos << " " << x << " >> " << (tp ^ 1) << " " << pos << " " << ((s[pos] - '0') ^ x) << endl;
    if (s[pos] != '?' && !dfs(tp ^ 1, pos, (s[pos] - '0') ^ x)) {
        return false;
    }
    return true;
}

void clr() {
    for (int p : v) {
        if (a[0][p] != 3) {
            a[0][p] = -1;
        }
        if (a[1][p] != 3) {
            a[1][p] = -1;
        }
    }
    v.clear();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    n = s.length();
    for (int len = 1; len < n; ++len) {
        LEN = len;
        sd = n - len;
        memset(a, -1, sizeof(a));
        memset(used, 0, sizeof(used));
        int add = 1;
        for (int j = 0; j <= n - j - 1; ++j) {
            if (s[j] == '?' && s[n - j - 1] == '?') {
                add = mul(add, 2);
                a[1][j] = a[1][n - j - 1] = 3;
            }
        }
        for (int j = 0; j <= len - j - 1; ++j) {
            if (s[sd + j] == '?' && s[sd + len - j - 1] == '?') {
                if (j) {
                    add = mul(add, 2);
                    a[0][sd + j] = a[0][sd + len - j - 1] = 3;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!used[j] && a[1][j] == -1) {
                int c = 0, ok = -1;
                int st = 0;
                if (j == 0) {
                    st = 1;
                }
                for (int b = st; b < 2; ++b) {
                    clr();
                    if (dfs(1, j, b)) {
                        ok = b;
                        ++c;
                    }
                }
                //cout << "len " << len << " " << j << " " << c << endl;
                if (ok == -1) {
                    add = 0;
                    break;
                }
                clr();
                dfs(1, j, ok);
                //cout << endl << endl;
                for (int p : v) {
                    used[p] = 1;
                }
                add = mul(add, c);
            }
        }
        //cout << len << ": " << add << endl;
        ans = (ans + add) % mod;
    }
    /*int subs = 1;
    for (int i = 0; i <= n - i - 1; ++i) {
        if (s[i] == '?' && s[n - i - 1] == '?') {
            subs = mul(subs, 2);
        } else if (subs[i] == '?' || subs[n - i - 1] == '?') {
        } else if (subs[i] != subs[i - 1]) {
            subs =
        }
    }*/
    printf("%d\n", ans);
    return 0;
}