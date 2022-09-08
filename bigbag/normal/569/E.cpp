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

const int max_n = 422, inf = 1111111111;

int cnt, n, m, k[max_n], used[max_n], qqq[max_n];
vector<int> g[max_n], rg[max_n], q;
char minc = '@';
string s, tp;

int get_v(int poz, char c, char ok) {
    poz *= 2;
    if (c == ok) {
        ++poz;
    }
    return poz;
}

bool dfs(int v, int tp) {
    //cout << v << " " << used[v] << "  tp = " << tp << endl;
    if (used[v] != -1 && used[v] != tp) {
        return false;
    }
    if (used[v] != -1) {
        return true;
    }
    used[v] = tp;
    v = v * 2 + tp;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i] / 2, f = g[v][i] % 2;
        if (dfs(to, f) == false) {
            return false;
        }
    }
    return true;
}

void clear() {
    for (int j = 0; j < s.length(); ++j) {
        used[j] = k[j];
    }
}

bool ok(int poz) {
    return true;
}

void write(int x, int y) {
    char Q[2];
    Q[1] = 'C';
    Q[0] = 'V';
    cout << "(" << x / 2 << " " << Q[x % 2] << ") -> (" << y / 2 << " " << Q[y % 2] << ")" << endl;
}

void dfs1(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs1(g[v][i]);
        }
    }
    q.push_back(v);
}

void dfs2(int v) {
    used[v] = cnt;
    for (int i = 0; i < rg[v].size(); ++i) {
        if (used[rg[v][i]] == 0) {
            dfs2(rg[v][i]);
        }
    }
}

bool bad() {
    for (int i = 0; i < 2 * s.length(); ++i) {
        if (used[i] == 0) {
            dfs1(i);
        }
    }
    reverse(q.begin(), q.end());
    memset(used, 0, sizeof(used));
    for (int i = 0; i < q.size(); ++i) {
        if (used[q[i]] == 0) {
            ++cnt;
            dfs2(q[i]);
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (used[2 * i] == used[2 * i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> tp >> n >> m;
    for (int i = 1; i < tp.length(); ++i) {
        if (tp[i] != tp[0]) {
            minc = i + 'a';
            break;
        }
    }
    while (m--) {
        int poz1, poz2;
        char c1, c2;
        cin >> poz1 >> c1 >> poz2 >> c2;
        --poz1;
        --poz2;
        g[get_v(poz1, c1, 'C')].push_back(get_v(poz2, c2, 'C'));
        rg[get_v(poz2, c2, 'C')].push_back(get_v(poz1, c1, 'C'));
        g[get_v(poz2, c2, 'V')].push_back(get_v(poz1, c1, 'V'));
        rg[get_v(poz1, c1, 'V')].push_back(get_v(poz2, c2, 'V'));
    }
    cin >> s;
    if (bad()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = s.length(); i >= 0; --i) {
        bool f = 1;
        memset(used, -1, sizeof(used));
        for (int j = 0; j < i; ++j) {
            f &= dfs(j, tp[s[j] - 'a'] == 'C');
        }
        if (f) {
            if (i == s.length()) {
                cout << s << endl;
                return 0;
            }
            qqq['C'] = qqq['V'] = 0;
            for (int j = 0; j < s.length(); ++j) {
                k[j] = used[j];
            }
            for (char c = s[i] + 1; c < 'a' + tp.length(); ++c) {
                if (qqq[tp[c - 'a']]) {
                    continue;
                }
                clear();
                qqq[tp[c - 'a']] = 1;
                /*cout << i << " " << c << " : ";
                for (int j = 0; j < s.length(); ++j) {
                    cout << used[j] << " ";
                }
                cout << endl;*/
                if (dfs(i, tp[c - 'a'] == 'C')) {
                    s[i] = c;
                    if (ok(i + 1)) {
                        for (int j = i + 1; j < s.length(); ++j) {
                            if (dfs(j, tp[0] == 'C')) {
                                s[j] = 'a';
                            } else if (minc != '@') {
                                clear();
                                if (dfs(j, tp[minc - 'a'] == 'C')) {
                                    s[j] = minc;
                                } else {
                                    cout << "FAIL" << endl;
                                    return 228;
                                }
                            } else {
                                f = 0;
                                break;
                            }
                            for (int w = 0; w < s.length(); ++w) {
                                k[w] = used[w];
                            }
                        }
                        if (f) {
                            cout << s << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}