#include <bits/stdc++.h>

using namespace std;

int n, T, ans = 0, restore = -1;

struct task {
    int p, time, num;
};

bool operator < (task a, task b) {
    return a.time < b.time;
}

vector<task> a, b;

bool check(int cur_p) {
    vector<int> times;
    for (int i = 0; i < n; ++i) {
        if (a[i].p >= cur_p) {
            times.push_back(a[i].time);
        }
    }
    sort(times.begin(), times.end());
    int t1 = T, cnt = 0;
    for (int i = 0; i < times.size(); ++i) {
        if (times[i] <= t1) {
            t1 -= times[i];
            cnt++;
        }
    }
    int res = min(cnt, cur_p);
    if (res >= ans) {
        ans = res;
        restore = cur_p;
    }
    if (cur_p <= cnt)
        return 0;
    else
        return 1;
}

int binsearch(int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (check(mid + 1) == 0)
        return binsearch(mid + 1, r);
    else
        return binsearch(l, mid);
}

int main()
{
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        int p, time;
        cin >> p >> time;
        a.push_back({p, time, i + 1});
    }
    int pos = binsearch(1, n);
    check(pos);
    if (pos < n)
        check(pos + 1);
    vector<int> tasks;
    for (int i = 0; i < n; ++i) {
        if (a[i].p >= restore)
            b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < ans; ++i) {
        tasks.push_back(b[i].num);
    }
    cout << ans << endl;
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << tasks[i] << " ";
    }
    cout << endl;
    return 0;
}