#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_v = 2 * max_n;

int tot, n, hp[max_n], res[max_n];
int first, val[max_v], l[max_v], r[max_v], num[max_v];
vector<int> all;
vector<vector<pair<int, int>>> ans;
int first_num;

void split(int id, int x) {
    l[all[id]] = ++first;
    val[first] = x;
    num[first] = num[all[id]];

    r[all[id]]= ++first;
    val[first] = val[all[id]] - x;
    num[first] = ++first_num;

    all[id] = first - 1;
    all.push_back(first);
}

void write(int id, int enemy) {
    //cout << id << " " << enemy << endl;
    if (l[id]) {
        write(l[id], enemy);
        write(r[id], enemy);
    } else {
        res[num[id]] = enemy;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &tot, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &hp[i]);
    }
    val[first] = tot;
    all.push_back(first);
    int cnt = (accumulate(hp, hp + n, 0) + tot - 1) / tot;
    int cur = 0;
    ans.resize(cnt);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < all.size(); ++j) {
            if (hp[cur] < val[all[j]] && cur + 1 < n) {
                split(j, hp[cur]);
            }
            hp[cur] -= val[all[j]];
            ans[i].push_back({all[j], cur});
            if (hp[cur] == 0 && cur + 1 < n) {
                ++cur;
            }
        }
    }
    while (all.size() < n) {
        all.push_back(first + 1);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) {
        printf("%d ", val[all[i]]);
    }
    puts("");
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < n; ++j) {
            res[j] = 0;
        }
        for (const pair<int, int> &p : ans[i]) {
            write(p.first, p.second);
        }
        for (int j = 0; j < n; ++j) {
            printf("%d ", res[j] + 1);
        }
        puts("");
    }
    return 0;
}