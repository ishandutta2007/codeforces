/**
 *  created: 05/04/2021, 19:59:41
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2 * 200222, inf = 1000111222;

struct DoublyLinkedList {
    list<int> a, b;
    list<int>::iterator mxa, mxb;

    DoublyLinkedList() {
    }

    DoublyLinkedList(int x): a{x}, b{x} {
        mxa = --a.end();
        mxb = b.begin();
    }

    DoublyLinkedList(const initializer_list<int> &v): a(v), b(v) {
        b.reverse();

        mxa = --a.end();
        mxb = b.begin();
    }

    void combine(DoublyLinkedList &l, bool f) {
        a.splice(a.end(), l.a);
        l.b.splice(l.b.end(), b);
        b.swap(l.b);

        if (f) {
            mxa = l.mxa;
            mxb = l.mxb;
        }
    }

    void reverse() {
        a.swap(b);
        swap(mxa, mxb);
    }
};

int n, a[max_n], b[max_n], pos_a[max_n], pos_b[max_n];
int used[max_n];
DoublyLinkedList dl[max_n];

void solve_rec(vector<int> &tps, int l, int r) {
    if (l > r) {
        return;
    }
    if (l + 1 == r) {
        assert(tps[l] != tps[r]);
        dl[l] = {l, l + 1, l + 2};
        if (tps[l]) {
            dl[l].reverse();
        }
        return;
    }
    if (tps[l] != tps[r]) {
        solve_rec(tps, l + 1, r - 1);
        dl[r] = {r + 1};
        bool f = 1;
        if (tps[l]) {
            swap(dl[l], dl[r]);
            f = 0;
        }
        dl[l + 1].reverse();
        dl[l].combine(dl[l + 1], 0);
        dl[l].combine(dl[r], f);
    } else {
        int bal1 = 0, bal2 = 0, len = 0;
        do {
            if (tps[l + len]) {
                ++bal1;
            } else {
                --bal1;
            }
            if (tps[r - len]) {
                ++bal2;
            } else {
                --bal2;
            }
            ++len;
        } while (bal1 && bal2);
        if (!bal2) {
            len = r - l + 1 - len;
        }
        solve_rec(tps, l, l + len - 1);
        solve_rec(tps, l + len, r);

        dl[l].a.splice(next(dl[l].mxa), dl[l + len].a);
        dl[l].a.erase(dl[l].mxa);
        dl[l].mxa = dl[l + len].mxa;

        dl[l].b.splice(next(dl[l].mxb), dl[l + len].b);
        dl[l].b.erase(dl[l].mxb);
        dl[l].mxb = dl[l + len].mxb;
    }
}

vector<int> solve(vector<int> &all_pos, vector<int> &tps) {
    for (int i = 0; i < tps.size(); ++i) {
        dl[i] = {i};
    }
    solve_rec(tps, 1, tps.size() - 2);
    dl[0].combine(dl[1], 1);
    vector<int> res;
    for (int i : dl[0].a) {
        res.push_back(all_pos[i]);
    }
    return res;
}

vector<int> solve() {
    for (int i = 0; i < 2 * n; ++i) {
        pos_a[a[i] + n] = i;
        pos_b[b[i] + n] = i;
        used[i] = 0;
    }
    vector<int> res;
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i] && a[i] > 0 && b[i] > 0) {
            int tp = 0, pos = i;
            vector<int> all_pos, tps;
            while (!used[pos]) {
                all_pos.push_back(pos);
                used[pos] = 1;
                if (tp == 0) {
                    tps.push_back(a[pos] > 0);
                    pos = pos_a[-a[pos] + n];
                } else {
                    tps.push_back(b[pos] < 0);
                    pos = pos_b[-b[pos] + n];
                }
                tp ^= 1;
            }
            if (tps.size() / 2 - 1 == accumulate(tps.begin(), tps.end(), 0)) {
                rotate(all_pos.begin(), all_pos.begin() + 1, all_pos.end());
                reverse(all_pos.begin() + 1, all_pos.end());
                reverse(tps.begin() + 1, tps.end());
                for (int &x : tps) {
                    x ^= 1;
                }
            }
            if (tps.size() / 2 + 1 != accumulate(tps.begin(), tps.end(), 0)) {
                return {};
            }
            bool ok = 0;
            for (int i = 0; i < tps.size(); ++i) {
                if (tps[i] == 1 && tps[(i + tps.size() - 1) % tps.size()] == 1 && a[all_pos[i]] > 0) {
                    ok = 1;
                    rotate(tps.begin(), tps.begin() + i, tps.end());
                    rotate(all_pos.begin(), all_pos.begin() + i, all_pos.end());
                    break;
                }
            }
            vector<int> v = solve(all_pos, tps);
            res.insert(res.end(), v.begin(), v.end());
        }
    }
    if (res.size() != 2 * n) {
        return {};
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    vector<int> ans = solve();
    if (ans.empty()) {
        puts("NO");
    } else {
        puts("YES");
        for (int i : ans) {
            printf("%d %d\n", a[i], b[i]);
        }
    }
    return 0;
}