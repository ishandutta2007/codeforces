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

const int max_n = 2022, inf = 1111111111;

int n, m, a[max_n], b[max_n];
long long s1, s2, ans, p1, p2, p3, p4;
vector<pair<int, int> > res;
vector<pair<long long, pair<int, int> > > v;

long long myabs(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s1 += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        s2 += b[i];
    }
    ans = myabs(s1 - s2);
    p1 = p2 = p3 = p4 = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s1 -= a[i];
            s2 += a[i];
            s2 -= b[j];
            s1 += b[j];

            if (myabs(s1 - s2) < ans) {
                ans = myabs(s1 - s2);
                p1 = i;
                p2 = j;
            }

            s1 += a[i];
            s2 -= a[i];
            s2 += b[j];
            s1 -= b[j];
        }
    }
    if (n > 1 && m > 1) {
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                v.push_back(make_pair(2LL * (b[i] + b[j]), make_pair(i, j)));
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long q = 2LL * (a[i] + a[j]);
                long long x = s1 - s2;
                x -= q;
                x *= -1;
                int l = 0, r = v.size();
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (v[mid].first <= x) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                x *= -1;
                //cout << x << " " << v[l].first << endl;
                x += v[l].first;
                if (myabs(x) < ans) {
                    ans = myabs(x);
                    p1 = i;
                    p2 = v[l].second.first;
                    p3 = j;
                    p4 = v[l].second.second;
                }

                x -= v[l].first;
                ++l;
                if (l < v.size()) {
                    x += v[l].first;
                    if (myabs(x) < ans) {
                        ans = myabs(x);
                        p1 = i;
                        p2 = v[l].second.first;
                        p3 = j;
                        p4 = v[l].second.second;
                    }
                }
            }
        }
    }
    if (p1 != -1) {
        res.push_back(make_pair(p1, p2));
    }
    if (p3 != -1) {
        res.push_back(make_pair(p3, p4));
    }
    cout << ans << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
    }
    return 0;
}