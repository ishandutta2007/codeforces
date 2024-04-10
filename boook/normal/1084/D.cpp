#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 300000 + 100
#define inf 0x3f3f3f3f
 
int n, m, w[maxn];
vector<PII> v[maxn];
long long ans = 0;
 
int u[maxn], z[maxn];
void CalcSize(int now, int fa) {
    z[now] = 1;
    for (auto to : v[now]) {
        if (u[to.F] == 0 && to.F != fa)
            CalcSize(to.F, now), z[now] += z[to.F];
    }
}
pair<int, int> GetCenter(int now, int fa, int sum) {
    pair<int, int> val = make_pair(n, now);
    int big = sum - z[now];
    for (auto to : v[now]) {
        if (u[to.F] == 0 && to.F != fa) {
            big = max(big, z[to.F]);
            val = min(val, GetCenter(to.F, now, sum));
        }
    }
    return min(val, make_pair(big, now));
}
long long Solve(int now, int fa, long long val) {
    long long big = 0;
    for (auto to : v[now]) {
        if (u[to.F] == 0 && to.F != fa) 
            big = max(big, Solve(to.F, now, val - to.S + w[to.F]));
    }
    return max(big, val);
}
void Centroid(int now) {
    CalcSize(now, now);
    now = GetCenter(now, now, z[now]).second;
 
    long long v1 = 0, v2 = 0, v3;
    for (auto to : v[now]) {
        if (u[to.F] == 0) {
            v3 = Solve(to.F, now, w[to.F] - to.S);
            if (v2 < v3) swap(v2, v3);
            if (v1 < v2) swap(v1, v2);
        }
    }
    ans = max(ans, v1 + v2 + w[now]);
    
    u[now] = 1;
    for (auto to : v[now]) {
        if (u[to.F] == 0) Centroid(to.F);
    }
    u[now] = 0;
}

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    for (int i = 2; i <= n; ++ i) {
        int v0, v1, v2;
        cin >> v0 >> v1 >> v2;
        v[v0].emplace_back(v1, v2);
        v[v1].emplace_back(v0, v2);
    }
 
    Centroid(1);
 
    printf("%lld\n", ans);
    return 0;
}