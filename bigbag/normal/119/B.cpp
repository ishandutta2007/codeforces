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

const int max_n = 111, inf = 1111111111;

int n, m, k, mn = inf, mx = -inf, a[max_n], used[max_n];
vector<int> v;
set<vector<int> > q;

void write(int a, int b) {
    if (a == 0) {
        cout << "0 ";
        return;
    }
    int f = 0;
    int x = a;
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int o = 0;
    for (int i = 0; i < v.size(); ++i) {
        o = o * 10 + v[i];
        int res = o / b;
        o %= b;
        if (res == 0 && f == 0) {
            continue;
        }
        ++f;
        cout << res;
    }
    cout << ".";
    for (int i = 0; i < 15; ++i) {
        o = o * 10;
        cout << o / b;
        o %= b;
    }
    cout << " ";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    int cnt = n / k;
    while (m--) {
        int sum = 0;
        for (int i = 0; i < cnt; ++i) {
            int num;
            cin >> num;
            v.push_back(num);
            used[num] = 1;
            sum += a[num];
        }
        sort(v.begin(), v.end());
        q.insert(v);
        v.clear();
        mx = max(mx, sum);
        mn = min(mn, sum);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            v.push_back(a[i]);
        }
    }
    if (q.size() < k && v.size() >= cnt) {
        sort(v.begin(), v.end());
        int sum = 0;
        for (int i = 0; i < cnt; ++i) {
            sum += v[i];
        }
        mn = min(mn, sum);
        mx = max(mx, sum);
        reverse(v.begin(), v.end());
        sum = 0;
        for (int i = 0; i < cnt; ++i) {
            sum += v[i];
        }
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    write(mn, cnt);
    write(mx, cnt);
    return 0;
}