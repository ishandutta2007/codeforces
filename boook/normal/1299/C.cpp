#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1000000 + 10

int n, aaa[maxn];
struct djs{
    int x[maxn], sum[maxn], siz[maxn];
    void init(){ 
        for (int i = 0; i < maxn; ++ i)
            x[i] = i, sum[i] = aaa[i], siz[i] = 1;
    }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){
        a = Find(a);
        b = Find(b);
        x[b] = a;
        sum[a] += sum[b];
        siz[a] += siz[b];
    }
    int operator[](int a){ return Find(a); }
} ds;

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> aaa[i];
    ds.init();

    for (int i = 2; i <= n; ++ i) {
        int pre = ds[i - 1];
        // cout << "i = " << i << " pre = " << pre << endl;
        // if ((ds.sum[pre] + x[i]) / (ds.siz[pre] + 1) < ds.sum[pre] / ds.siz[pre])
        if ((ds.sum[pre] + aaa[i]) * ds.siz[pre] < ds.sum[pre] * (ds.siz[pre] + 1)) {
            // cout << "[here] " << endl;
            ds.Union(pre, i);
            int v2 = ds[pre];
            int v1 = ds[v2 - 1];
// while (v1 != 0 && (ds.sum[v1] + ds.sum[v2]) / (ds.siz[v1] + ds.siz[v2]) < ds.sum[v1] / ds.siz[v1])
    while (v1 != 0 && (ds.sum[v1] + ds.sum[v2]) * ds.siz[v1] < ds.sum[v1] * (ds.siz[v1] + ds.siz[v2])) {
        ds.Union(v1, v2);
        v2 = ds[pre];
        v1 = ds[v2 - 1];
    }
        }
    }

    // for (int i = 1; i <= n; ++ i) 
    //     cout << ds[i] << " \n"[i == n];
    // for (int i = 1; i <= n; ++ i) 
    //     cout << ds.sum[ds[i]] << " \n"[i == n];
    // for (int i = 1; i <= n; ++ i) 
    //     cout << ds.siz[ds[i]] << " \n"[i == n];

    for (int i = 1; i <= n; ++ i) 
        cout << fixed << setprecision(10) << (double)ds.sum[ds[i]] / ds.siz[ds[i]] << "\n";
    return 0;
}