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

const int max_n = 1111111, inf = 1111111111;

int len[2], cnt[2][11][max_n], a[11], p[2 * max_n];
char s[2][max_n];
string ans;

int get_len(int x) {
    if (x == 0) {
        return 1;
    }
    int res = 0;
    memset(a, 0, sizeof(a));
    while (x) {
        ++res;
        ++a[x % 10];
        x /= 10;
    }
    return res;
}

bool cmp(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] < s2[i];
        }
    }
    return false;
}

int get(int i, int l) {
    if (l == 0) {
        return cnt[1][i][len[1] - 1];
    }
    return cnt[1][i][len[1] - 1] - cnt[1][i][l - 1];
}

bool ok(int l) {
    for (int i = 0; i <= 9; ++i) {
        if (a[i] < get(i, l)) {
            return false;
        }
    }
    return true;
}

void write(string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '#') {
            s[i] += '0';
        }
    }
    cout << s << endl;
}

pair<bool, string> get(int ll) {
    string res = "", ss = "";
    for (int i = 0; i < len[1]; ++i) {
        ss += s[1][i];
    }
    ss += "#";
    p[0] = 0;
    for (int i = 1; i < ss.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && ss[i] != ss[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (ss[i] == ss[p[i]]) {
            ++p[i];
        }
    }
    int fff = 0;
    for (int i = 0; i < ll; ++i) {
        int st = 0;
        if (i == 0) {
            st = 1;
        }
        int mn = inf;
        ss += 'Q';
        for (int j = st; j <= 9; ++j) {
            if (a[j]) {
                --a[j];

                int poz = ss.length() - 1;
                ss[poz] = j;
                p[poz] = p[poz - 1];
                while (p[poz] > 0 && ss[poz] != ss[p[poz]]) {
                    p[poz] = p[p[poz] - 1];
                }
                if (ss[poz] == ss[p[poz]]) {
                    ++p[poz];
                }
                if (p[poz] == len[1]) {
                    fff = 1;
                }

                if (fff == 1) {
                    mn = j;
                    break;
                }
                if (ok(p[poz])) {
                    mn = j;
                    //cout << "@" << p[poz] << "   ";
                    //write(ss);
                    break;
                }
                ++a[j];
            }
        }
        if (mn == inf) {
            return make_pair(false, "");
        }
        res += mn + '0';
        //cout << "!" << res << endl;
    }
    return make_pair(true, res);
}

void proc() {
    string q = s[0];
    if (q == "01" || q == "10") {
        cout << "0" << endl;
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2; ++i) {
        scanf("%s", s[i]);
    }
    proc();
    for (int i = 0; i < 2; ++i) {
        len[i] = strlen(s[i]);
        for (int j = 0; j < len[i]; ++j) {
            s[i][j] -= '0';
            if (j) {
                for (int k = 0; k < 10; ++k) {
                    cnt[i][k][j] = cnt[i][k][j - 1];
                }
            }
            ++cnt[i][s[i][j]][j];
        }
    }
    for (int l = 0; l <= len[0]; ++l) {
        ans += '9';
    }
    for (int l = 1; l <= len[0]; ++l) {
        int x = get_len(l);
        if (l + x == len[0]) {
            //cout << l << endl;
            for (int i = 0; i < 10; ++i) {
                a[i] = cnt[0][i][len[0] - 1] - a[i];
                //cout << a[i] << " ";
            }
            //cout << endl;
            pair<bool, string> q = get(l);
            if (q.first) {
                if (cmp(q.second, ans)) {
                    ans = q.second;
                }
            }
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}