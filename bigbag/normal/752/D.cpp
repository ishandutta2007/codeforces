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

const int max_n = 111111, inf = 1011111111;

int n, m, ans, f[max_n], num[max_n];
pair<int, string> p[max_n];
set<pair<string, pair<int, int> > > q;
char s[max_n];

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

void add(int num) {
    f[num] = 1;
    ans += p[num].first;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", s, &p[i].first);
        p[i].second = s;
    }
    sort(p, p + n);
    reverse(p, p + n);
    memset(num, -1, sizeof(num));
    for (int i = 0; i < n; ++i) {
        q.insert(make_pair(p[i].second, make_pair(-p[i].first, i)));
        //cout << p[i].second << " " << p[i].first << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (!q.count(make_pair(p[i].second, make_pair(-p[i].first, i)))) {
            continue;
        }
        q.erase(make_pair(p[i].second, make_pair(-p[i].first, i)));
        string r = rev(p[i].second);
        //cout << i << " " << r << endl;
        auto it = q.lower_bound(make_pair(r, make_pair(-inf, -inf)));
        if (it == q.end()) {
            continue;
        }
        pair<string, pair<int, int> > a = *it;
        if (r == a.first) {
            num[i] = a.second.second;
            q.erase(a);
        }
        //cout << i << " " << num[i] << endl;
    }
    int fff = 0;
    pair<int, int> mx = make_pair(-inf, -inf);
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            continue;
        }
        if (num[i] != -1) {
            if (p[i].first >= 0 && p[num[i]].first >= 0) {
                add(i);
                add(num[i]);
            } else if (p[i].first >= 0) {
                if (rev(p[i].second) == p[i].second) {
                    if (p[i].first + p[num[i]].first >= 0) {
                        mx = max(mx, make_pair(-p[num[i]].first, i));
                    } else {
                        mx = max(mx, make_pair(p[i].first, i));
                    }
                }
            }
        } else if (rev(p[i].second) == p[i].second) {
            mx = max(mx, make_pair(p[i].first, i));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == mx.second) {
            ans += max(0, p[i].first);
            continue;
        }
        if (f[i] == 0 && num[i] != -1) {
            if (p[i].first >= 0) {
                if (p[i].first + p[num[i]].first >= 0) {
                    ans += p[i].first + p[num[i]].first;
                    f[num[i]] = 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}