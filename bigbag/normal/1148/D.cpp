#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, a[max_n], b[max_n];
vector<pair<int, int>> v1, v2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] < b[i]) {
            v1.push_back({-a[i], i});
        } else {
            v2.push_back({a[i], i});
        }
    }
    if (v1.size() < v2.size()) {
        v1.swap(v2);
    }
    sort(v1.begin(), v1.end());
    printf("%d\n", v1.size());
    for (const pair<int, int> &p : v1) {
        printf("%d ", p.second + 1);
    }
    return 0;
}