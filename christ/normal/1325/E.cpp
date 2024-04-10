#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
vector<int> adj[1000005];
int dist[1000005], par[1000005];
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n); set<int> seen; int ans = INT_MAX; vector<int> att, nodes;
    for (auto &au : a) {
        scanf ("%d",&au);
        if (seen.count(au)) ans = 2;
        seen.insert(au);
        int cur = au, fac1 = -1, fac2 = -1;
        for (int i = 2; i * i <= cur; i++) if (cur%i==0) {
            int cnt = 0;
            while (cur%i==0) cur /= i, cnt++;
            if (cnt&1) (~fac1 ? fac2 : fac1) = i;
        }
        if (cur > 1) (~fac1 ? fac2 : fac1) = cur;
        if (!(~fac1)) return !printf ("1\n");
        if (!(~fac2)) fac2 = 1;
        adj[fac1].push_back(fac2); adj[fac2].push_back(fac1);
        if (fac1 <= 1000) att.push_back(fac1);
        if (fac2 <= 1000) att.push_back(fac2);
        nodes.push_back(fac1); nodes.push_back(fac2);
    }
    if (ans == 2) return !printf ("2\n");
    sort(all(att)); att.erase(unique(all(att)),att.end());
    sort(all(nodes)); nodes.erase(unique(all(nodes)),nodes.end());
    for (int st : att) {
        for (int i : nodes) dist[i] = n+3, par[i] = 0;
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i : adj[cur]) {
                if (dist[cur] + 1 < dist[i]) {
                    dist[i] = dist[cur] + 1;
                    par[i] = cur;
                    q.push(i);
                } else if (i != par[cur]) {
                    ans = min(ans,dist[cur]+dist[i]+1);
                }
            }
        }
    }
    printf ("%d\n",ans > n ? -1 : ans);
    return 0;
}