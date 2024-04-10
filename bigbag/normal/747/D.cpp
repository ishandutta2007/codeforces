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

int n, k, a[max_n];
vector<pair<int, int> > v;

int solve(int n, int k, int res) {
    if (k < 0) {
        return inf;
    }
    vector<int> q;
    //cout << k << " " << res << " : ";
    for (int i = 0; i < n; ++i) {
        //cout << "(" << v[i].first << " " << v[i].second << ") ";
        if (v[i].second == 1) {
            q.push_back(v[i].first);
        }
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); ++i) {
        if (k >= q[i]) {
            k -= q[i];
            --res;
            --res;
        } else {
            break;
        }
    }
    //cout << "res = " << res << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }
    for (int i = 0; i < n; ) {
        int cnt = 0, pos = i;
        while (i < n && a[pos] == a[i]) {
            ++i;
            ++cnt;
        }
        if (pos == 0 && a[pos] == 1) {
            continue;
        }
        v.push_back(make_pair(cnt, a[pos]));
        if (a[pos] == 0) {
            k -= cnt;
        }
    }
    if (v.size() == 0) {
        printf("0\n");
        return 0;
    }
    if (k < 0) {
        printf("-1\n");
        return 0;
    }
    int ans = v.size();
    if (v.back().second == 1) {
        ans = min(ans, solve(v.size() - 1, k - v.back().first, v.size() - 1));
        ans = min(ans, solve(v.size() - 1, k, v.size()));
    } else {
        ans = min(ans, solve(v.size(), k, v.size()));
    }
    printf("%d\n", ans);
    return 0;
}