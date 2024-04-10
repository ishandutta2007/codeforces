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

const int max_n = 222222, inf = 1011111111;

int n, w, k, a[max_n], t[max_n], sum[2][max_n], used[max_n];
int sum_mx, tm[max_n];
set<pair<int, int> > q, s;

int get_sum(int tp, int l, int r) {
    if (l == 0) {
        return sum[tp][r];
    }
    return sum[tp][r] - sum[tp][l - 1];
}

void add(int x, int pos) {
    //cout << "+ " << x << " " << pos << endl;
    q.insert(make_pair(x, pos));
    sum_mx += x;
    if (q.size() > w) {
        pair<int, int> mn = *q.begin();
        q.erase(q.find(mn));
        s.insert(mn);
        sum_mx -= mn.first;
    }
}

void err(int x, int pos) {
    if (q.count(make_pair(x, pos))) {
        sum_mx -= x;
        q.erase(make_pair(x, pos));
    }
    if (s.count(make_pair(x, pos))) {
        s.erase(make_pair(x, pos));
    }
    if (s.size() && q.size() < w) {
        pair<int, int> p = *s.rbegin();
        q.insert(p);
        s.erase(p);
        sum_mx += p.first;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &w, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[0][i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
        tm[i] = t[i] - (t[i] + 1) / 2;
        sum[1][i] = t[i];
    }
    for (int i = 1; i < n; ++i) {
        sum[0][i] += sum[0][i - 1];
        sum[1][i] += sum[1][i - 1];
    }
    int pos = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        pos = max(pos, i);
        while (pos < n) {
            if (used[pos] == 0) {
                used[pos] = 1;
                add(tm[pos], pos);
            }
            int tm = get_sum(1, i, pos);
            tm -= sum_mx;
            /*if (i == 2) {
                cout << pos << ": " << tm + sum_mx << " " << sum_mx << endl;
            }*/
            if (tm <= k) {
                ++pos;
            } else {
                break;
            }
        }
        //cout << i << " " << pos - 1 << "    #" << q.size() << " " << sum_mx << endl;
        ans = max(ans, get_sum(0, i, pos - 1));
        err(tm[i], i);
    }
    printf("%d\n", ans);
    return 0;
}