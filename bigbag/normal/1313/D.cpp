#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_mask = 266;

int n, m, k, curb[max_n];
int q1 = 0, q2 = 1, dp[2][max_mask];
vector<pair<int, int>> v;

int get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int get_mask(const set<int> &ids, const set<int> &nids, int nid, int mask, int b) {
    int pos = 0;
    for (int id : ids) {
        curb[id] = get_bit(mask, pos);
        ++pos;
    }
    int res = 0;
    pos = -1;
    for (int id : nids) {
        ++pos;
        if (id == nid) {
            res += b << pos;
        } else {
            res += curb[id] << pos;
        }
    }
    return res;
}

int get_del(const set<int> &ids, int num, int mask) {
    int pos = -1, pos_new = 0, res = 0;
    for (int id : ids) {
        ++pos;
        if (id == num) {
            continue;
        }
        res += get_bit(mask, pos) << pos_new;
        ++pos_new;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back({l, i});
        v.push_back({r + 1, -i - 1});
    }
    sort(v.begin(), v.end());
    set<int> ids;
    for (int i = 0; i + 1 < v.size(); ++i) {
        set<int> nids = ids;
        int id = v[i].second;
        memset(dp[q2], 0, sizeof(dp[q2]));
        if (id >= 0) {
            nids.insert(id);
            for (int mask = 0; mask < (1 << ids.size()); ++mask) {
                for (int b = 0; b < 2; ++b) {
                    int add = 0;
                    if ((__builtin_popcount(mask) + b) % 2) {
                        add = v[i + 1].first - v[i].first;
                    }
                    const int to = get_mask(ids, nids, id, mask, b);
                    dp[q2][to] = max(dp[q2][to], dp[q1][mask] + add);
                }
            }
        } else {
            id = -id - 1;
            int num = 0;
            /*for (int x : ids) {
                cout << x << " ";
            }
            cout << ", id = " << id << ": ";*/
            for (int x : ids) {
                if (x == id) {
                    //cout << "#" << num << endl;
                    break;
                }
                ++num;
            }

            for (int mask = 0; mask < (1 << ids.size()); ++mask) {
                int add = 0;
                if ((__builtin_popcount(mask) - get_bit(mask, num)) % 2) {
                    add = v[i + 1].first - v[i].first;
                }
                const int to = get_del(ids, id, mask);
                dp[q2][to] = max(dp[q2][to], dp[q1][mask] + add);
            }
            nids.erase(id);
        }
        assert(nids.size() <= k);
        ids.swap(nids);
        swap(q1, q2);
    }
    int ans = *max_element(dp[q1], dp[q1] + max_mask);
    printf("%d\n", ans);
    return 0;
}