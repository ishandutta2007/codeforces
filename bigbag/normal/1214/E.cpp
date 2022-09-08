#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n;
pair<int, int> p[max_n];
vector<int> v;

void write(int x, int y) {
    printf("%d %d\n", x + 1, y + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p, p + n);
    reverse(p, p + n);
    for (int i = 0; i < n; ++i) {
        v.push_back(2 * p[i].second);
    }
    for (int i = 0; i + 1 < n; ++i) {
        write(2 * p[i].second, 2 * p[i + 1].second);
    }
    for (int i = 0; i < n; ++i) {
        int cur = 2 * p[i].second + 1;
        write(v[i + p[i].first - 1], cur);
        if (i + p[i].first >= v.size()) {
            v.push_back(cur);
        }
    }
    return 0;
}