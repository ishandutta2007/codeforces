#include <bits/stdc++.h>
using namespace std;

const int maxn = 200090;

int n, m;

struct djs{
    int x[maxn];
    void init() {
        for (int i = 0; i < maxn; i ++) x[i] = i;
    }
    int find(int now) {
        return x[now] == now ? now : x[now] = find(x[now]);
    }
    void unions(int v1, int v2) {
        v1 = find(v1), v2 = find(v2);
        x[min(v1, v2)] = max(v1, v2);
    }
    int operator[](int now) {
        return find(now);
    }
} ds;

int main(){
    cin.tie(0), cout.sync_with_stdio(0);

    cin >> n >> m;
    
    ds.init();
    for (int i = 1; i <= m; i ++) {
        int v1, v2; cin >> v1 >> v2;
        ds.unions(v1, v2);
    }

    int idx = 1, ans = 0;

    while (idx <= n) {
        int now = idx, to = ds[idx];
        while (now <= to) {
            if (ds[now] != ds[idx]) ds.unions(now, idx), ans ++;
            to = ds[idx];
            now ++;
        }
        idx = to + 1;
    }

    cout << ans << endl;
    return 0;
}