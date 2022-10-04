#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 3e5;
const int INF = 1e9;

int n, t[4 * mx];

void build(vector<int> &a, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int get(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int res_l = get(l, min(r, tm), v * 2, tl, tm);
    int res_r = get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    return max(res_l, res_r);
}

int k, used[mx], deg[mx];
vector<int> a, t1[mx], t2;

void run(int pos) {
    while (pos >= 1 && used[pos] == -1) {
        a.push_back(pos);
        used[pos] = a.size() - 1;
        pos--;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n + 2; ++i) {
        used[i] = -1;
        deg[i] = -2;
    }
    a.resize(k);
    vector<int> to_run = {n + 1};
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        used[a[i]] = i;
        to_run.push_back(a[i]);
    }
    sort(to_run.begin(), to_run.end());
    for (int i = 0; i < to_run.size(); ++i) {
        run(to_run[i] - 1);
    }
    build(a);
    for (int i = 1; i <= n - 1; ++i) {
        int pos1 = used[i];
        int pos2 = used[i + 1];
        if (pos2 >= pos1 - 1)
            continue;
        int min_seg = get(pos2 + 1, pos1 - 1);
        if (min_seg > i + 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}