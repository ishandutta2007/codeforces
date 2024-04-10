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

const int max_n = 111, inf = 1111111111;

int n, m, k, a[3], b[3];
char s[max_n][max_n][max_n];

bool is_in() {
    return 0 <= a[0] && a[0] < n && 0 <= a[1] && a[1] < m && 0 <= a[2] && a[2] < k && 0 <= b[0] && b[0] < n && 0 <= b[1] && b[1] < m && 0 <= b[2] && b[2] < k;
}

void write() {
    cout << "(";
    for (int i = 0; i < 3; ++i) {
        cout << a[i];
        if (i < 2) {
            cout << " ";
        } else {
            cout << ")";
        }
    }
    cout << " -> (";
    for (int i = 0; i < 3; ++i) {
        cout << b[i];
        if (i < 2) {
            cout << " ";
        } else {
            cout << ")";
        }
    }
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%s", s[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int q = 0; q < k; ++q) {
                if (s[i][j][q] == '0') {
                    continue;
                }
                int res = 0;
                for (int w = 0; w < 3; ++w) {
                    for (int e = 0; e < 3; ++e) {
                        a[0] = b[0] = i;
                        a[1] = b[1] = j;
                        a[2] = b[2] = q;
                        --a[w];
                        ++b[e];
                        if (is_in()) {
                            if (s[a[0]][a[1]][a[2]] == '1' && s[b[0]][b[1]][b[2]] == '1') {
                                ++a[e];
                                if (s[a[0]][a[1]][a[2]] == '0' || w == e) {
                                    /*if (res == 0) {
                                        --a[e];
                                        cout << i << " " << j << " " << q << "  :  ";
                                        write();
                                    }*/
                                    res = 1;
                                }
                            }
                        }
                    }
                }
                /*if (res) {
                    cout << i << " " << j << " " << q << endl;
                }*/
                ans += res;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}