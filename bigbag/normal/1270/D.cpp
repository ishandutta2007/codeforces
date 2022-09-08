#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int n, k, a[max_n], used[max_n];
vector<int> q[max_n];

pair<int, int> query(const vector<int> &v) {
    cout << "? ";
    for (int pos : v) {
        cout << pos + 1 << " ";
    }
    cout << endl;
    int i, x;
    cin >> i >> x;
    --i;
    return {i, x};
}

void answer(int m) {
    cout << "! " << m << endl;
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k == 1) {
        answer(1);
    }
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n - k + 1; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (a[j] == -1 && v.size() < k) {
                v.push_back(j);
            }
        }
        pair<int, int> p = query(v);
        a[p.first] = p.second;
        q[p.first] = v;
    }
    int mn = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1 && (mn == -1 || a[i] < a[mn])) {
            mn = i;
        }
    }
    if (k <= n - k + 1) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1 && v.size() < k) {
                v.push_back(i);
            }
        }
        pair<int, int> p = query(v);
        int res = 1;
        for (int i : v) {
            if (a[i] != -1 && a[i] < p.second) {
                ++res;
            }
        }
        answer(res);
    }
    int res = 1;
    for (int i : q[mn]) {
        used[i] = 1;
    }
    int other;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            other = i;
        }
    }
    for (int i : q[mn]) {
        if (i == mn) {
            continue;
        }
        if (a[i] != -1) {
            res += a[i] < a[mn];
            continue;
        }
        vector<int> v;
        for (int j : q[mn]) {
            if (j != i) {
                v.push_back(j);
            }
        }
        v.push_back(other);
        if (query(v).first != mn) {
            ++res;
        }
    }
    answer(res);
    return 0;
}