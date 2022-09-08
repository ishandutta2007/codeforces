#include <map>
#include <set>
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

const int max_n = 22, inf = 11111;

struct state {
    int a, b;
    string s[max_n];
    bool operator < (const state &x) const {
        if (a != x.a || b != x.b) {
            return a < x.a || a == x.a && b < x.b;
        }
        for (int i = 0; i < a; ++i) {
            if (s[i] != x.s[i]) {
                return s[i] < x.s[i];
            }
        }
        return false;
    }
    void write() {
        cout << endl;
        for (int i = 0; i < a; ++i) {
            cout << s[i] << endl;
        }
        cout << endl;
    }
};

int n, m;
string s[max_n];

state povorot(state q) {
    state ret;
    ret.a = q.b;
    ret.b = q.a;
    for (int i = 0; i < ret.a; ++i) {
        for (int j = q.a - 1; j >= 0; --j) {
            ret.s[i] += q.s[j][i];
        }
    }
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    int ans = 0, ans_x = inf, ans_y = inf;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            for (int j = 1; j <= m; ++j) {
                if (m % j == 0) {
                    //cout << i << ' ' << j << endl;
                    map<state, int> M;
                    int fff = 0;
                    for (int k = 1; k <= n; k += i) {
                        for (int q = 0; q < m; q += j) {
                            state z;
                            z.a = i;
                            z.b = j;
                            for (int w = k; w < k + i; ++w) {
                                z.s[w - k] = s[w].substr(q, j);
                            }
                            map <state, int> mmm;
                            for (int r = 0; r < 4; ++r) {
                                if (!mmm.count(z)) {
                                    //if (i == 2 && j == 3) z.write();
                                    int x = M[z];
                                    if (x == 1) {
                                        fff = 1;
                                        break;
                                    }
                                    M[z] = x + 1;
                                    mmm[z] = 1;
                                }
                                z = povorot(z);
                            }
                            if (fff == 1) {
                                break;
                            }
                        }
                        if (fff == 1) {
                            break;
                        }
                    }
                    if (fff == 0) {
                        ++ans;
                        if (ans_x * ans_y > i * j || ans_x * ans_y == i * j && i < ans_x) {
                            ans_x = i;
                            ans_y = j;
                        }
                        //cout << i << ' ' << j << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl << ans_x << ' ' << ans_y << endl;
    return 0;
}