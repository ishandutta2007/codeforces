#include <bits/stdc++.h>

const int max_N = 210;

int n;
int a[max_N][max_N];

int ask(int i, int j) {
    if (a[i][j] != -1)
        return a[i][j];
    printf("? %d %d\n", i, j);
    fflush(stdout);
    static char s[10];
    scanf("%s", s);
    if (s[0] == '>') a[i][j] = 0, a[j][i] = 1;
    if (s[0] == '<') a[i][j] = 1, a[j][i] = 0;
    return a[i][j];
}

void answer() {
    puts("!");
    fflush(stdout);
}

int dfs(std::vector<int> vec) {
    if (vec.size() == 1) {
        return vec[0];
    }
    std::vector<int> tmp;
    for (int i = 0; i + 1 < vec.size(); i += 2) {
        if (ask(vec[i], vec[i + 1]) == 0) {
            tmp.push_back(vec[i + 1]);
        } else {
            tmp.push_back(vec[i]);
        }
    }
    if (vec.size() % 2 == 1) {
        tmp.push_back(vec.back());
    }
    return dfs(tmp);
}

void solve() {
    memset(a, -1, sizeof(a));
    scanf("%d", &n);

    std::vector<std::pair<int, int>> cev;
    for (int i = 1; i <= n; ++i) {
        if (ask(i, n + i) == 0) {
            cev.emplace_back(n + i, i);
        } else {
            cev.emplace_back(i, n + i);
        }
    }
    std::sort(cev.begin(), cev.end(), [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return ask(a.first, b.first) == 1;
    });

    int pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        int rank = i + 1;
        for (int j = 0; j < n; ++j) {
            if (ask(cev[i].first, cev[j].second) == 0) {
                ++rank;
            }
        }
        if (rank >= n) {
            pos = cev[i].first;
            break;
        }
    }
    if (pos == -1) {
        std::vector<int> vec;
        vec.push_back(cev[n - 1].first);
        for (int i = n - 1; i >= 0; --i) {
            vec.push_back(cev[i].second);
        }
        dfs(vec);
        answer();
        return;
    }
    std::vector<int> vec;
    for (int i = 1; i <= n + n; ++i) {
        if (i == pos) continue;
        if (ask(i, pos) == 1) {
            vec.push_back(i);
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            ask(vec[i], vec[j]);
        }
    }
    answer();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}