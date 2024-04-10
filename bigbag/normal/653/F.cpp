#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 500555, max_lev = 20, inf = 1111111111;

int n, last, a[max_lev][max_n], cl[max_lev][max_n], num[max_lev][max_n], sum[max_n], lcp[max_n];
int logs[max_n], mins[max_lev][max_n];
pair<int, pair<int, int> > p[max_n], p2[max_n];
string s;

bool cmp(int a, int b) {
    return s[a] < s[b] || s[a] == s[b] && a < b;
}

void my_sort(int n) {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; ++i) {
        ++sum[p[i].second.first + 1];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        p2[sum[p[i].second.first]++] = p[i];
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; ++i) {
        ++sum[p2[i].first + 1];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        p[sum[p2[i].first]++] = p2[i];
    }
}

void get_suffix_array(int n) {
    for (int i = 0; i < n; ++i) {
        a[0][i] = i;
    }
    sort(a[0], a[0] + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        num[0][a[0][i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        while (i + 1 < n && s[a[0][i]] == s[a[0][i + 1]]) {
            cl[0][i] = cnt;
            ++i;
        }
        cl[0][i] = cnt;
        ++cnt;
    }
    for (int lev = 1, len = 1; len <= n; ++lev, len *= 2) {
        for (int i = 0; i < n; ++i) {
            p[i] = make_pair(cl[lev - 1][num[lev - 1][i]], make_pair(cl[lev - 1][num[lev - 1][(i + len) % n]], i));
        }
        my_sort(n);
        //sort(p, p + n);
        for (int i = 0; i < n; ++i) {
            a[lev][i] = p[i].second.second;
            num[lev][a[lev][i]] = i;
        }
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            while (i + 1 < n && p[i].first == p[i + 1].first && p[i].second.first == p[i + 1].second.first) {
                cl[lev][i] = cnt;
                ++i;
            }
            cl[lev][i] = cnt;
            ++cnt;
        }
        last = lev;
        if (cnt == n) {
            return;
        }
    }
}

bool is_equal(int l1, int r1, int l2, int r2) {
    if (r1 - l1 != r2 - l2) {
        return false;
    }
    int lev = logs[r1 - l1 + 1];
    if (lev > last) {
        return false;
    }
    return cl[lev][num[lev][l1]] == cl[lev][num[lev][l2]] && cl[lev][num[lev][r1 - (1 << lev) + 1]] == cl[lev][num[lev][r2 - (1 << lev) + 1]];
}

void get_logs() {
    for (int i = 0, pw = 1; i < max_lev; ++i, pw *= 2) {
        for (int j = pw; j < pw * 2 && j < max_n; ++j) {
            logs[j] = i;
        }
    }
}

void get_lcp(int n) {
    get_logs();
    for (int i = 1; i < n; ++i) {
        int l1 = a[last][i - 1];
        int l2 = a[last][i];
        int l = 0, r = min(n - l1 + 1, n - l2 + 1);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (is_equal(l1, l1 + mid - 1, l2, l2 + mid - 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        lcp[i] = l;
    }
}

void get_all_mins(int n, int a[]) {
    for (int i = 1; i < n; ++i) {
        mins[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 1; j < n && j + (1 << (i - 1)) < n; ++j) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int get_min(int l, int r) {
    if (l > r) {
        return inf;
    }
    int lev = logs[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

void read() {
    char q[max_n];
    scanf("%d%s", &n, q);
    s = q;
    s += "#";
    ++n;
}

int nxt[max_lev][max_n], mn_poz[2 * max_n], bal[max_n], dp[max_n];

void get_all_bals() {
    int b = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '(') {
            ++b;
        } else {
            --b;
        }
        bal[i] = b;
    }
}

void get_all_nxt() {
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n; ++j) {
            if (nxt[i - 1][j] == -1) {
                nxt[i][j] = -1;
            } else {
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j] + 1];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    get_suffix_array(s.length());
    get_lcp(s.length());
    get_all_mins(s.length(), lcp);
    get_all_bals();
    memset(mn_poz, -1, sizeof(mn_poz));
    nxt[0][n - 1] = -1;
    for (int i = n - 2; i >= 0; --i) {
        nxt[0][i] = -1;
        if (s[i] == '(') {
            int x = bal[i] - 1 + max_n;
            if (mn_poz[x] != -1) {
                nxt[0][i] = mn_poz[x];
            }
        }
        if (nxt[0][i] != -1) {
            dp[i] = 1 + dp[nxt[0][i] + 1];
        }
        int x = bal[i] + max_n;
        mn_poz[x] = i;
    }
    get_all_nxt();
    /*for (int i = 0; i + 1 < n; ++i) {
        cout << i << " " << nxt[0][i] << endl;
    }*/
    long long ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        //cout << s.substr(a[last][i]) << " " << lcp[i] << endl;
        int poz = a[last][i] + lcp[i];
        int st = a[last][i];
        if (nxt[0][st] == -1) {
            continue;
        }
        for (int j = max_lev - 1; j >= 0; --j) {
            if (nxt[j][st] != -1 && nxt[j][st] < poz) {
                //cout << "@$@$$   " << j << " " << st << "  " << nxt[j][st] << " " << poz << endl;
                st = nxt[j][st] + 1;
            }
        }
        st = nxt[0][st];
        //cout << a[last][i] << "  poz = " << poz << "   st = " << st << endl;
        if (poz <= st) {
            ans += 1 + dp[st + 1];
            //cout << a[last][i] << "  st = " << st << "   ans += " << 1 + dp[st + 1] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}