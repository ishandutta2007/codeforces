#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 100011;

int n;
pair<int, int> a[max_n];

vector<int> factorize(int x) {
    vector<int> res;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        res.push_back(x);
    }
    return res;
}

int get_mask(const vector<int> &v, int x) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (x % v[i] == 0) {
            res += 1 << i;
        }
    }
    return res;
}

vector<int> update(const vector<int> &v, int st) {
    vector<int> res;
    for (int x : v) {
        int cnt = 0;
        for (int i = st; i < n; ++i) {
            if (a[i].first % x != 0) {
                ++cnt;
            }
        }
        if (cnt < 10) {
            res.push_back(x);
        }
    }
    return res;
}

const int max_mask = 1 << 9;
const int max_left = 111;

int ans[max_n];
vector<int> m1, m2;
bool dp[max_left][max_mask][max_mask];

bool solve(int x, int y, int st) {
    vector<int> v1 = factorize(x);
    vector<int> v2 = factorize(y);
    vector<pair<int, int>> all;
    //v1 = update(v1, st);
    v2 = update(v2, st);
    int full1 = (1 << v1.size()) - 1;
    int full2 = (1 << v2.size()) - 1;
    int mask1 = full1;
    int mask2 = full2;
    m1.clear();
    m2.clear();
    //cout << st << ": " << mask1 << " " << mask2 << endl;
    for (int i = st; i < n; ++i) {
        int mm1 = get_mask(v1, a[i].first);
        int mm2 = get_mask(v2, a[i].first);
        //cout << mm1 << " " << mm2 << ", a[i] = " << a[i].first << " " << v2[0] << endl;
        if (mm2 == full2) {
            if ((mask1 & mm1) != mask1) {
                ans[a[i].second] = 1;
                mask1 &= mm1;
            } else {
                ans[a[i].second] = 2;
            }
        } else {
            all.push_back(a[i]);
            m1.push_back(mm1);
            m2.push_back(mm2);
        }
    }
    //cout << "$" << mask1 << " " << mask2 << endl;
    if (!(all.size() + 1 < max_left)) {
        cout << "FAIL, " << all.size() << endl;
        exit(1);
    }
    for (int i = 0; i <= all.size(); ++i) {
        for (int m1 = 0; m1 <= mask1; ++m1) {
            memset(dp[i][m1], 0, mask2 + 1);
        }
    }
    dp[0][mask1][mask2] = 1;
    for (int i = 0; i < all.size(); ++i) {
        for (int cur1 = 0; cur1 <= mask1; ++cur1) {
            for (int cur2 = 0; cur2 <= mask2; ++cur2) {
                if (dp[i][cur1][cur2]) {
                    if ((cur1 & m1[i]) != cur1) {
                        dp[i + 1][cur1 & m1[i]][cur2] = 1;
                    }
                    dp[i + 1][cur1][cur2 & m2[i]] = 1;
                }
            }
        }
    }
    if (!dp[all.size()][0][0]) {
        return false;
    }
    int pos = all.size();
    int c1 = 0, c2 = 0;
    while (pos) {
        bool ok = false;
        --pos;
        //cout << pos << ": " << all[pos].second << endl;
        for (int cur1 = 0; cur1 <= mask1 && !ok; ++cur1) {
            for (int cur2 = 0; cur2 <= mask2 && !ok; ++cur2) {
                if (dp[pos][cur1][cur2]) {
                    if ((cur1 & m1[pos]) == c1 && cur2 == c2 && cur1 != c1) {
                        ans[all[pos].second] = 1;
                        c1 = cur1;
                        c2 = cur2;
                        ok = true;
                    } else if ((cur2 & m2[pos]) == c2 && cur1 == c1) {
                        ans[all[pos].second] = 2;
                        c1 = cur1;
                        c2 = cur2;
                        ok = true;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    //random_shuffle(a, a + n);
    vector<int> v = factorize(a[0].first);
    int full = get_mask(v, a[0].first);
    for (int i = 1; i < n; ++i) {
        if (full == get_mask(v, a[i].first)) {
            //swap(a[1], a[i]);
            break;
        }
    }
    int cur = a[0].first;
    ans[a[0].second] = 1;
    for (int i = 1; i < n; ++i) {
        ans[a[i].second] = 2;
        if (solve(cur, a[i].first, i + 1)) {
            puts("YES");
            //cout << "$" << i << endl;
            for (int j = 0; j < n; ++j) {
                printf("%d ", ans[j]);
            }
            return 0;
        }
        cur = __gcd(cur, a[i].first);
        int nfull = get_mask(v, a[i].first);
        if (full == nfull) {
            break;
        }
        ans[a[i].second] = 1;
        full = nfull;
    }
    puts("NO");
    return 0;
}