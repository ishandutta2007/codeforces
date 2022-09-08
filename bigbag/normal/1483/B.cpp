/**
 *  created: 21/03/2021, 15:45:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];
set<int> q, all;

int get_nxt(int pos) {
    auto it = all.upper_bound(pos);
    if (it == all.end()) {
        it = all.begin();
    }
    return *it;
}

int get_prev(int pos) {
    auto it = all.lower_bound(pos);
    if (it == all.begin()) {
        return *all.rbegin();
    } else {
        --it;
    }
    return *it;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        q.clear();
        all.clear();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            all.insert(i);
            if (__gcd(a[i], a[(i + 1) % n]) == 1) {
                q.insert((i + 1) % n);
            }
        }
        int last = 0;
        while (!q.empty()) {
            auto it = q.upper_bound(last);
            if (it == q.end()) {
                it = q.begin();
            }
            int pos = *it;
            q.erase(pos);
            all.erase(pos);
            ans.push_back(pos);
            if (all.empty()) {
                break;
            }
            int nxt = get_nxt(pos);
            last = nxt;
            if (__gcd(a[pos], a[nxt]) == 1) {
                //assert(q.find(nxt) != q.end());
                q.erase(nxt);
            }
            int pr = get_prev(pos);
            if (__gcd(a[pr], a[nxt]) == 1) {
                q.insert(nxt);
            }
        }
        printf("%d", ans.size());
        for (int id : ans) {
            printf(" %d", id + 1);
        }
        puts("");
    }
    return 0;
}