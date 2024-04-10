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

const int max_n = 111, prec = 311111, inf = 1011111111;

int n, a[max_n];
long long k, ans;

long long get(long long d) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int x = d - a[i] % d;
        if (x != d) {
            res += x;
        }
    }
    return res;
}

set<int> q;

void upd(long long i) {
    /*if (q.count(i)) {
        return;
    }
    q.insert(i);*/
    if (get(i) <= k) {
        ans = max(ans, i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i <= prec; ++i) {
        upd(i);
    }
    vector<long long> v;
    v.push_back(prec);
    for (int i = 0; i < n; ++i) {
        int cur = prec;
        while (a[i] >= cur) {
            int l = cur, r = a[i] + 2, x = a[i] / cur;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (x == a[i] / mid) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cur = l;
            v.push_back(cur + 1);
            ++cur;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.push_back(1e12);
    for (int i = 0; i + 1 < v.size(); ++i) {
        long long a = get(v[i]), b = get(v[i] + 1);
        if (a <= k) {
            long long cnt = v[i + 1] - v[i];
            if (a < b) {
                cnt = min(cnt, (k - a) / (b - a));
            }
            ans = max(ans, v[i] + cnt);
        }
    }
    cout << ans << endl;
    return 0;
}