#include <bits/stdc++.h>

using namespace std;

const int max_n = 402222, inf = 1000111222;

int n, l[max_n], r[max_n], a[max_n], b[max_n], p[max_n];
vector<int> all[max_n], cycle;

int val[max_n];
set<int> not_used, open;

void write() {
    puts("NO");
    for (int i = 0; i < n; ++i) {
        a[i] -= n;
        printf("%d ", a[i] + 1);
    }
    puts("");
    copy(a, a + n, b);
    assert(cycle.size() % 2 == 0);
    if (cycle[1] >= n) {
        rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
    }
    for (int i = 1; i < cycle.size(); i += 2) {
        //cout << cycle[i] << ": " << cycle[i - 1] - n << endl;
        b[cycle[i]] = cycle[i - 1] - n;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", b[i] + 1);
    }
    puts("");
    exit(0);
}

void dfs(int v) {
    //cout << "$" << v << endl;
    val[v] = 1;
    not_used.erase(v);
    open.insert(v);
    auto it = open.lower_bound(l[v]);
    if (it != open.end()) {
        if (*it == a[v]) {
            ++it;
        }
        if (it != open.end() && *it <= r[v]) {
            //cout << "cycle " << v << " " << *it << endl;
            cycle.push_back(*it);
            while (v != *it) {
                cycle.push_back(v);
                v = p[v];
            }
            write();
        }
    }
    while (true) {
        auto it = not_used.lower_bound(l[v]);
        if (it == not_used.end() || *it > r[v]) {
            break;
        }
        if (*it == a[v]) {
            ++it;
            if (it == not_used.end() || *it > r[v]) {
                break;
            }
        }
        p[*it] = v;
        //cout << v << " -> " << *it << endl;
        dfs(*it);
    }
    val[v] = 2;
    open.erase(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        --l[i];
        --r[i];
        all[l[i]].push_back(i);
    }
    set<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int id : all[i]) {
            q.insert({r[id], id});
        }
        auto it = q.begin();
        a[it->second] = i;
        q.erase(it);
    }
    for (int i = 0; i < n; ++i) {
        l[i] += n;
        r[i] += n;
        a[i] += n;
        a[a[i]] = -1;
        l[a[i]] = i;
        r[a[i]] = i;
    }
    for (int i = 0; i < 2 * n; ++i) {
        not_used.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (!val[i]) {
            dfs(i);
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i] - n + 1);
    }
    puts("");
    return 0;
}