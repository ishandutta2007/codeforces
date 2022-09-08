/**
 *  created: 18/02/2021, 16:56:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, k, a[max_n];

bool check(int x) {
    vector<pair<int, int>> v;
    v.push_back({0, -1});
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= x) {
            ++sum;
        } else {
            --sum;
        }
        auto it = lower_bound(v.rbegin(), v.rend(), make_pair(sum, -inf));
        if (it != v.rbegin()) {
            --it;
            int len = i - it->second;
            //cout << i - len + 1 << " " << i << endl;
            if (len >= k) {
                return true;
            }
        }
        if (v.back().first > sum) {
            v.push_back({sum, i});
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}