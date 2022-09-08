#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<long long, int>> v;

long long q(int t, int i, int j, int k) {
    ++i;
    ++j;
    ++k;
    cout << t << " " << i << " " << j << " " << k << endl;
    long long res;
    cin >> res;
    return res;
}

bool cmp(int a, int b) {
    return q(2, 0, a, b) > 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int sec = 1;
    for (int i = 2; i < n; ++i) {
        if (cmp(i, sec)) {
            sec = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (i == sec) {
            continue;
        }
        v.push_back({q(1, 0, sec, i), i});
    }
    sort(v.begin(), v.end());
    vector<int> v1, v2;
    int mx = v.back().second;
    for (auto p : v) {
        int i = p.second;
        if (i == mx || i == sec) {
            continue;
        }
        if (cmp(i, mx)) {
            v1.push_back(i);
        } else {
            v2.push_back(i);
        }
    }
    reverse(v2.begin(), v2.end());
    vector<int> v;
    v.push_back(0);
    v.push_back(sec);
    for (int id : v1) {
        v.push_back(id);
    }
    v.push_back(mx);
    for (int id : v2) {
        v.push_back(id);
    }
    cout << 0 << " ";
    for (int id : v) {
        cout << id + 1 << " ";
    }
    cout << endl;
    return 0;
}