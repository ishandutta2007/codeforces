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

const int max_n = 111, inf = 11111111;

int n, s, k[max_n], v[max_n][max_n], t[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            cin >> v[i][j] >> t[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector < pair<int, pair<int, int> > > vv;
            int x = 0;
            for (int q = 0; q < k[i]; ++q) {
                vv.push_back(make_pair(t[i][q] + x, make_pair(v[i][q], 1)));
                x += t[i][q];
                //cout << "!!!" << x << "!!!" << endl;
            }
            x = 0;
            for (int q = 0; q < k[j]; ++q) {
                vv.push_back(make_pair(t[j][q] + x, make_pair(v[j][q], 2)));
                x += t[j][q];
            }
            vv.push_back(make_pair(inf, make_pair(0, 1)));
            vv.push_back(make_pair(0, make_pair(0, 1)));
            sort(vv.begin(), vv.end());
            double v1 = v[i][0], v2 = v[j][0], s1 = 0, s2 = 0;
            int cnt1 = 0, cnt2 = 0, f = 0;
            for (int q = 1; q + 1 < vv.size(); ++q) {
                //cout << i << ' ' << j << "   -   " << vv[q].first << ' ' << v1 << ' ' << v2 << "  =  " << ans << endl;
                double t = vv[q].first - vv[q - 1].first, s11 = s1 + v1 * t, s22 = s2 + v2 * t;
                if (s1 != 0 && s2 != 0) {
                    if (f == 1 && s11 > s22 || f == 0 && s22 > s11) {
                        ++ans;
                    }
                }
                s1 = s11;
                s2 = s22;
                if (s1 < s2) {
                    f = 1;
                }
                if (s1 > s2) {
                    f = 0;
                }
                if (vv[q].second.second == 1) {
                    ++cnt1;
                    v1 = v[i][cnt1];
                } else {
                    ++cnt2;
                    if (cnt2 == k[j]) {
                        --cnt2;
                    }
                    v2 = v[j][cnt2];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}