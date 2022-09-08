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

const int max_n = 1111111;

int n, cnt, a[max_n], sum[max_n];
long long ans;
set<int> s;
map<int, int> q, x;
vector<int> v2;
vector<pair<int, int> > v;

void update(int x) {
    for (; x <= cnt; x = (x | (x + 1))) {
        ++sum[x];
    }
}

int get_sum(int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        res += sum[x];
    }
    return res;
}

void proc() {
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i = 0; i < v2.size(); ++i) {
        ++cnt;
        x[v2[i]] = cnt;
    }
}

int get_sum(int l, int r) {
    return get_sum(x[r]) - get_sum(x[l]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (!q.count(x)) {
            q[x] = x;
        }
        if (!q.count(y)) {
            q[y] = y;
        }
        swap(q[x], q[y]);
    }
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it) {
        pair<int, int> p = *it;
        swap(p.first, p.second);
        v2.push_back(p.first);
        swap(p.first, p.second);
        v2.push_back(p.first - 1);
        v2.push_back(p.second - 1);
        v2.push_back(p.second);
        v.push_back(p);
    }
    proc();
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        a[i] = x[v[i].second];
        //cout << a[i] << " ";
    }
    //cout << endl;
    for (int i = v.size() - 1; i >= 0; --i) {
        ans += get_sum(a[i]);
        update(a[i]);
    }
    //cout << ans << endl;
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < v.size(); ++i) {
        pair<int, int> p = v[i];
        if (p.second >= p.first - 1) {
            update(x[p.first]);
            //cout << " + " << x[p.second] << endl;
            continue;
        }
        int cnt = p.first - p.second - 1 - get_sum(p.second, p.first - 1);
        //cout << i << " " << cnt << "  " << p.first << " " << p.second << "  " << get_sum(p.second, p.first - 1) << endl;
        update(x[p.first]);
        //cout << " + " << x[p.second] << endl;
        ans += cnt;
    }
    //cout << ans << endl;
    memset(sum, 0, sizeof(sum));
    //cout << "!" << get_sum(1, 3) << endl;
    for (int i = v.size() - 1; i >= 0; --i) {
        pair<int, int> p = v[i];
        if (p.second <= p.first + 1) {
            update(x[p.first]);
            //cout << " + " << x[p.second] << endl;
            continue;
        }
        int cnt = p.second - p.first - 1 - get_sum(p.first, p.second - 1);
        //cout << i << " " << cnt << "  " << p.second - p.first - 1 << "   " << get_sum(p.first, p.second - 1) <<  "        " << x[p.first] << " " << x[p.second - 1] << endl;
        update(x[p.first]);
        ans += cnt;
        //cout << " + " << x[p.second] << endl;
    }
    cout << ans << endl;
    return 0;
}