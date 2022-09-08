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

const int max_n = 111111, inf = 1111111111;

long long n, k, a[max_n];

long long fun(long long x) {
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += min(x, a[i]);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k) {
        cout << -1 << endl;
        return 0;
    }
    if (sum == k) {
        return 0;
    }
    int l = -1, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (fun(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    --r;
    long long qqq = fun(r), lp = 0;
    //cout << qqq << endl;
    vector<int> ans, vvv;
    for (int i = 0; i < n; ++i) {
        if (a[i] > r) {
            ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < k - qqq; ++i) {
        int x = ans[i];
        lp = i;
        if (a[x - 1] > r + 1) {
            vvv.push_back(x);
        }
        /*for (int i = lp + 1; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
        for (int i = 0; i < vvv.size(); ++i) {
            cout << vvv[i] << ' ';
        }
        cout << endl;*/
    }
    for (int i = lp + 1; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    for (int i = 0; i < vvv.size(); ++i) {
        cout << vvv[i] << ' ';
    }
    return 0;
}