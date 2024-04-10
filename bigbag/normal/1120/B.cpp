#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_op = 100000;
//const int max_op = 0;

int n;
char a[max_n], b[max_n];
vector<pair<int, int>> ans;

bool increase(int pos);
bool decrease(int pos);

bool increase(int pos) {
    if (pos + 1 == n) {
        return false;
    }
    if (a[pos + 1] == '9') {
        if (!decrease(pos + 1)) {
            return false;
        }
    }
    ans.push_back({pos, 1});
    ++a[pos];
    ++a[pos + 1];
    return true;
}

bool decrease(int pos) {
    if (pos + 1 == n) {
        return false;
    }
    if (a[pos + 1] == '0') {
        if (!increase(pos + 1)) {
            return false;
        }
    }
    ans.push_back({pos, -1});
    --a[pos];
    --a[pos + 1];
    return true;
}

set<int> not9[2];
set<int> not0[2];

void del(int pos) {
    if (a[pos] != '9') {
        not9[pos % 2].erase(pos);
    }
    if (a[pos] != '0') {
        not0[pos % 2].erase(pos);
    }
}

void add(int pos) {
    if (a[pos] != '9') {
        not9[pos % 2].insert(pos);
    }
    if (a[pos] != '0') {
        not0[pos % 2].insert(pos);
    }
}

int fast_increase(int pos) {
    int num0 = pos % 2;
    int num9 = num0 ^ 1;
    int to = min(*not0[num0].lower_bound(pos + 2), *not9[num9].lower_bound(pos + 1));
    if (to == n) {
        return -1;
    }
    del(to);
    if (to % 2 == pos % 2) {
        --a[to];
    } else {
        ++a[to];
    }
    add(to);
    del(pos);
    ++a[pos];
    add(pos);
    return to - pos;
}

int fast_decrease(int pos) {
    int num9 = pos % 2;
    int num0 = num9 ^ 1;
    int to = min(*not0[num0].lower_bound(pos + 1), *not9[num9].lower_bound(pos + 2));
    if (to == n) {
        return -1;
    }
    del(to);
    if (to % 2 == pos % 2) {
        ++a[to];
    } else {
        --a[to];
    }
    add(to);
    del(pos);
    --a[pos];
    add(pos);
    return to - pos;
}

long long solve() {
    long long res = 0;
    not0[0].insert(n);
    not0[1].insert(n);
    not9[0].insert(n);
    not9[1].insert(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != '9') {
            not9[i % 2].insert(i);
        }
        if (a[i] != '0') {
            not0[i % 2].insert(i);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        while (a[i] < b[i]) {
            int cnt = fast_increase(i);
            //cout << "inc " << i << ", cnt = " << cnt << endl;
            if (cnt == -1) {
                return -1;
            }
            res += cnt;
        }
        while (a[i] > b[i]) {
            int cnt = fast_decrease(i);
            //cout << "dec " << i << ", cnt = " << cnt << endl;
            if (cnt == -1) {
                return -1;
            }
            res += cnt;
        }
    }
    if (a[n - 1] != b[n - 1]) {
        return -1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i + 1 < n && ans.size() < max_op; ++i) {
        while (a[i] < b[i] && ans.size() < max_op) {
            if (!increase(i)) {
                puts("-1");
                return 0;
            }
        }
        while (a[i] > b[i] && ans.size() < max_op) {
            if (!decrease(i)) {
                puts("-1");
                return 0;
            }
        }
    }
    long long cnt = solve();
    if (cnt == -1) {
        puts("-1");
        return 0;
    }
    cnt += ans.size();
    printf("%I64d\n", cnt);
    for (int i = 0; i < min(max_op, (int) ans.size()); ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second);
    }
    return 0;
}