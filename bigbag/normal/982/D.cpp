#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
vector<pair<int, int>> all_k;
set<pair<int, int>> qlen, qpos;

void er(int x, int len) {
    qpos.erase({x, len});
    qlen.erase({len, x});
}

void ins(int x, int len) {
    qpos.insert({x, len});
    qlen.insert({len, x});
}

void del(int pos) {
    set<pair<int, int>>::iterator it = qpos.upper_bound({pos + 1, -1});
    --it;
    int x = it->first, len = it->second;
    er(x, len);
    if (x < pos) {
        ins(x, pos - x);
    }
    if (pos + 1 < x + len) {
        ins(pos + 1, x + len - pos - 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    all_k.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all_k[i] = {a[i] + 1, i};
    }
    sort(all_k.begin(), all_k.end());
    reverse(all_k.begin(), all_k.end());
    ins(0, n);
    pair<int, int> ans(0, 0);
    for (int i = 0; i < all_k.size(); ) {
        if (qlen.begin()->first == qlen.rbegin()->first) {
            ans = max(ans, make_pair((int) qlen.size(), -all_k[i].first));
        }
        int cur = i;
        while (cur < all_k.size() && all_k[i].first == all_k[cur].first) {
            int pos = all_k[cur].second;
            del(pos);
            ++cur;
        }
        i = cur;
    }
    printf("%d\n", -ans.second);
    return 0;
}