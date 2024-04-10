#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 1100
#define inf 0x3f3f3f3f

int n;
vector<int> v[maxn];
int u[maxn], z[maxn];

void CalcSize(int now, int fa) {
    z[now] = 1;
    for (auto to : v[now]) {
        if (u[to] == 0 && to != fa)
            CalcSize(to, now), z[now] += z[to];
    }
}
pair<int, int> GetCenter(int now, int fa, int sum) {
    pair<int, int> val = make_pair(n, now);
    int big = sum - z[now];
    for (auto to : v[now]) {
        if (u[to] == 0 && to != fa) {
            big = max(big, z[to]);
            val = min(val, GetCenter(to, now, sum));
        }
    }
    return min(val, make_pair(big, now));
}
int qz[maxn][maxn];
int query(int v1, int v2) {
    // cout << "[v1] = " << v1 << " " << v2 << endl;
    if (qz[v1][v2] != 0) return qz[v1][v2];
    cout << "? " << v1 << " " << v2 << "\n"; cout.flush();
    int ans; cin >> ans;
    qz[v1][v2] = qz[v2][v1] = ans;
    return qz[v1][v2];
}
void Centroid(int now) {
    CalcSize(now, now);
    now = GetCenter(now, now, z[now]).second;

    vector<int> sol;
    for (auto to : v[now]) if (u[to] == 0) sol.emplace_back(to);

    if (sol.size() == 0) {
        cout << "! " << now << "\n"; exit(0);
    }
    else if (sol.size() == 1) {
        int ans = query(now, sol[0]);
        u[now ^ ans ^ sol[0]] = 1;
        Centroid(ans);
    }
    else{
        int ans = query(sol[0], sol[1]);
        if (ans == now) {
            u[sol[0]] = u[sol[1]] = 1;
            Centroid(ans);
        }
        else {
            u[now] = 1;
            Centroid(ans);
        }
    }
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    for (int i = 2; i <= n; ++ i) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].emplace_back(v2);
        v[v2].emplace_back(v1);
    }
    Centroid(1);

    return 0;
}