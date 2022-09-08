#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;
const int max_c = 26;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int n, nxt[max_n][max_c];
string s;

/*bool ok(const string &s) {
    string t = s;
    sort(t.begin(), t.end());
    int cnt[max_c];
    do {
        bool ok = true;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i + 1 < s.length(); ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
            bool f = false;
            for (int j = 0; j < max_c; ++j) {
                if (cnt[j]) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                ok = false;
                break;
            }
        }
        if (ok) {
            //cout << t << endl;
            return true;
        }
    } while (next_permutation(t.begin(), t.end()));
    return false;
}*/

bool check(const string &s) {
    if (s.length() == 1) {
        return 1;
    }
    set<char> q(s.begin(), s.end());
    if (q.size() >= 3) {
        return true;
    }
    return s[0] != s.back();
}

/*int num;

void rec(string s) {
    if (s.length() && check(s) != ok(s)) {
        cout << s << " " << ok(s) << endl;
        exit(0);
    }
    if (s.length() == 5) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        string t = s;
        t += 'a' + i;
        rec(t);
    }
}*/

bool fast(int l, int r) {
    if (l == r) {
        return 1;
    }
    int diff = 0;
    for (int c = 0; c < max_c; ++c) {
        if (nxt[l][c] <= r) {
            ++diff;
        }
    }
    if (diff >= 3) {
        return true;
    }
    return s[l] != s[r];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    s = read();
    for (int i = 0; i < max_c; ++i) {
        nxt[s.length()][i] = s.length();
    }
    for (int i = s.length() - 1; i >= 0; --i) {
        for (int j = 0; j < max_c; ++j) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        if (fast(l, r)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}