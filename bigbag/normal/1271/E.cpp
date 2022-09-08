#include <bits/stdc++.h>

using namespace std;

const int max_n = -1;

long long n, k;
vector<int> vn;

vector<int> getv(long long x) {
    vector<int> res;
    while (x) {
        res.push_back(x % 2);
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

long long get(long long x) {
    if (x > n) {
        return 0;
    }
    vector<int> vx = getv(x);
    long long res = 0;
    long long sn = 0;
    for (int i = 0; i < vx.size(); ++i) {
        sn = sn * 2 + vn[i];
    }
    int diff = vn.size() - vx.size();
    for (int i = 0; i < diff; ++i) {
        res += 1LL << i;
    }
    if (sn > x) {
        res += 1LL << diff;
    } else if (sn == x) {
        res += n - (sn << diff) + 1;
    }
    if (x % 2 == 0) {
        res += get(x + 1);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    vn = getv(n);
    long long l = 0, r = n + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (get(2 * mid) >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    long long ans = 2 * l;
    l = 0;
    r = n + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (get(2 * mid + 1) >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans = max(2 * l + 1, ans);
    cout << ans << endl;
    return 0;
}