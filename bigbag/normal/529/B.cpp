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

const int max_n = 1111;

int n;
int ans = 2000000000, a[max_n], b[max_n];
vector<int> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first - p1.second > p2.first - p2.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int x = 1; x <= 1000; ++x) {
        int s1 = 0, s2 = 0, k = 0, cnt = 0;
        vector<pair<int, int> > v;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x && b[i] > x) {
                break;
            }
            ++k;
            if (a[i] <= x && b[i] <= x) {
                v.push_back(make_pair(a[i], b[i]));
                //s1 = max(s1, max(a[i], b[i]));
                //s2 += min(a[i], b[i]);
            } else {
                s1 = max(s1, min(a[i], b[i]));
                s2 += max(a[i], b[i]);
                if (a[i] < b[i]) {
                    ++cnt;
                }
            }
        }
        if (k == n && cnt <= n / 2) {
            sort(v.begin(), v.end(), cmp);
            cnt = n / 2 - cnt;
            for (int i = 0; i < v.size(); ++i) {
                //cout << v[i].first << " " << v[i].second << endl;
                if (i < cnt && v[i].first > v[i].second) {
                    swap(v[i].first, v[i].second);
                }
                s1 = max(s1, v[i].second);
                s2 += v[i].first;
            }
            //cout << x << " " << s1 << " " << s2 << " " << cnt << endl;
            ans = min(ans, s1 * s2);
        }
    }
    cout << ans << endl;
    return 0;
}