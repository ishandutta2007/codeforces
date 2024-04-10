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

const int max_n = 100011, inf = 1111111111;

int n, x[max_n], y[max_n], cntx[max_n], cnty[max_n];
vector<int> vx[max_n], vy[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        ++cntx[x[i]];
        ++cnty[y[i]];
    }
    for (int i = 0; i < n; ++i) {
        if (cntx[x[i]] > 1) {
            vx[x[i]].push_back(y[i]);
        }
        if (cnty[y[i]] > 1) {
            vy[y[i]].push_back(x[i]);
        }
    }
    int maxx = -1, maxy = -1, pozx, pozy;
    for (int i = 0; i <= 100000; ++i) {
        if (maxx < (int) vx[i].size()) {
            maxx = (int) vx[i].size();
            pozx = i;
        }
        if (maxy < (int) vy[i].size()) {
            maxy = (int) vy[i].size();
            pozy = i;
        }
    }
    if (n == 97330) {
        //cout << pozx << ' ' << pozy << endl;
    }
    if (maxx < maxy) {
        for (int i = 0; i <= 100000; ++i) {
            sort(vx[i].begin(), vx[i].end());
        }
        int ans = 0;
        for (int i = 0; i <= 100000; ++i) {
            if (i != pozx) {
                for (int j = 0; j < vx[i].size(); ++j) {
                    for (int k = j + 1; k < vx[i].size(); ++k) {
                        int x1 = vx[i][j], x2 = vx[i][k];
                        int r = x2 - x1;
                        if (i + r <= 100000) {
                            vector<int>::iterator it1 = find(vx[i + r].begin(), vx[i + r].end(), x1);
                            vector<int>::iterator it2 = find(vx[i + r].begin(), vx[i + r].end(), x2);
                            if (it1 != vx[i + r].end() && it2 != vx[i + r].end()) {
                                ++ans;
                            }
                        }
                        if (i - r == pozx) {
                            vector<int>::iterator it1 = find(vx[i - r].begin(), vx[i - r].end(), x1);
                            vector<int>::iterator it2 = find(vx[i - r].begin(), vx[i - r].end(), x2);
                            if (it1 != vx[i - r].end() && it2 != vx[i - r].end()) {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    } else {
        for (int i = 0; i <= 100000; ++i) {
            sort(vy[i].begin(), vy[i].end());
        }
        int ans = 0;
        for (int i = 0; i <= 100000; ++i) {
            if (i != pozy) {
                for (int j = 0; j < vy[i].size(); ++j) {
                    for (int k = j + 1; k < vy[i].size(); ++k) {
                        int y1 = vy[i][j], y2 = vy[i][k];
                        int r = y2 - y1;
                        if (i + r <= 100000) {
                            vector<int>::iterator it1 = find(vy[i + r].begin(), vy[i + r].end(), y1);
                            vector<int>::iterator it2 = find(vy[i + r].begin(), vy[i + r].end(), y2);
                            if (it1 != vy[i + r].end() && it2 != vy[i + r].end()) {
                                ++ans;
                            }
                        }
                        if (i - r == pozy) {
                            vector<int>::iterator it1 = find(vy[i - r].begin(), vy[i - r].end(), y1);
                            vector<int>::iterator it2 = find(vy[i - r].begin(), vy[i - r].end(), y2);
                            if (it1 != vy[i - r].end() && it2 != vy[i - r].end()) {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}