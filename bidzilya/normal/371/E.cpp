#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 3e5 + 100;

int n, k;
pair<ll, int> x[max_n];
ll d[max_n];

int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first;
        x[i].second = i;
    }
    cin >> k;
    sort(x, x + n);
    d[n - 1] = 0;
    for (int i = n - 2; i >= n - k; --i) {
        d[i] = d[i + 1];
        d[i] += (x[i + 1].first - x[i].first) * (n - 1 - i);
    }
    for (int i = n - k - 1; i >= 0; --i) {
        d[i] = d[i + 1];
        d[i] += (x[i + 1].first - x[i].first) * (k - 1);
        d[i] -= (x[i + k].first - x[i + 1].first);
    }
    ll c_ans = 0;
    for (int i = n - 1; i >= n - k; --i)
        c_ans += d[i];
    ll ans = c_ans;
    int ans_pos = n - k;
    for (int i = n - k - 1; i >= 0; --i) {
        c_ans -= (x[i + k].first - x[i].first) * (k - 1);
        c_ans += d[i] * 2;
        if (c_ans < ans) {
            ans = c_ans;
            ans_pos = i;
        }
    }
    for (int i = ans_pos; i < ans_pos + k; ++i)
        cout << x[i].second + 1 << " ";
    cout << endl;
    return 0;
}