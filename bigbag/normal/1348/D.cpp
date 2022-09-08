#include <bits/stdc++.h>

using namespace std;

int t;

vector<int> solve(int n) {
    if (n == 2) {
        return {0};
    }
    if (n == 3) {
        return {1};
    }
    vector<int> res;
    long long cnt = 1, sum = 1;
    while (sum < n) {
        res.push_back(cnt);
        cnt *= 2;
        sum += cnt;
    }
    sum -= cnt;
    cnt /= 2;
    res.pop_back();
    if (n >= sum + cnt) {
        res.push_back(n - (sum + cnt));
        return res;
    }
    assert(res.size());
    sum -= cnt;
    cnt /= 2;
    res.pop_back();
    long long l = 0, r = cnt + 1;
    //cout << cnt << " " << sum << endl;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        long long ncnt = cnt + mid;
        long long nsum = sum + ncnt;
        if (n >= nsum + ncnt) {
            l = mid;
        } else {
            r = mid;
        }
    }
    res.push_back(l);
    cnt += l;
    sum += cnt;
    res.push_back(n - (sum + cnt));
    return res;
}

long long func(const vector<int> &v) {
    int cnt = 1, sum = 1;
    for (int x : v) {
        assert(0 <= x && x <= cnt);
        cnt += x;
        sum += cnt;
    }
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v = solve(n);
        cout << v.size() << "\n";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}