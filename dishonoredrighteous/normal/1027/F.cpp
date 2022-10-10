#include <bits/stdc++.h>

typedef long long ll;

const int N = 2000100;

int curShit = 1;
int mt[N], a[N], b[N];
int used[N];
std::vector<int> g[N];
std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

bool kuhn(int v) {
    if (used[v] == curShit) {
        return false;
    }
    used[v] = curShit;

    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }

    for (auto to : g[v]) {
        if (kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main(void) {
    int n;
    scanf("%d", &n);
    std::vector<int> trans;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        --a[i];
        --b[i];
        trans.push_back(a[i]);
        trans.push_back(b[i]);
    }
    memset(mt, -1, sizeof(mt));
    std::sort(trans.begin(), trans.end());
    trans.resize(std::unique(trans.begin(), trans.end()) - trans.begin());
    // for (auto i : trans) {
    //  std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    for (int i = 0; i < n; ++i) {
        int first = std::lower_bound(trans.begin(), trans.end(), a[i]) - trans.begin();
        int second = std::lower_bound(trans.begin(), trans.end(), b[i]) - trans.begin();
        g[first].push_back(i);
        g[second].push_back(i);
        // std::cerr << first << ' ' << i << '\n' << second << ' ' << i << '\n';
    }

    for (int i = 0; i < n; ++i) {
        std::shuffle(g[i].begin(), g[i].end(), rnd);
    }

    bool ansFl = false;
    int cur = 0;
    for (int i = 0; i < (int)trans.size(); ++i) {
        // memset(used, false, sizeof(used));
        if (kuhn(i)) {
            ++curShit;
            ++cur;
            if (cur == n) {
                ansFl = true;
                break;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //  std::cerr << mt[i] << ' ';
    // }
    // std::cerr << '\n';
    if (!ansFl) {
        printf("-1\n");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, trans[mt[i]]);
    }
    printf("%d\n", ans + 1);
    return 0;
}