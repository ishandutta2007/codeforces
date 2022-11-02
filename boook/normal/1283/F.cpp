#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10

int n, x[maxn], u[maxn], p[maxn];
int use[maxn];

vector<int> v[maxn];

void dfs(int now) {
    if (use[now]) return ;
    use[now] = 1;
    for (auto to : v[now]) dfs(to);
}

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i < n; ++ i) cin >> x[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i < n; ++ i) u[x[i]] ++;
    for (int i = 1; i <= n; ++ i) if (u[i] == 0) pq.push(i);
    
    int pos = n - 1;
    for (int i = 1; i < n; ++ i) {
        if (pq.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        int now = pq.top(); pq.pop();
//        cout << "now = " << now << endl;
        p[now] = x[pos];
        
        v[p[now]].push_back(now);
        v[now].push_back(p[now]);

        u[x[pos]] --;
        if (u[x[pos]] == 0) pq.push(x[pos]);//, cout << "push = " << x[pos] << endl;
        pos --;
    }

    int root = pq.top();
//    cout << "root = " << root << endl;
    dfs(root);

    for (int i = 1; i <= n; ++ i) if (use[i] == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << root << endl;
    for (int i = 1; i <= n; ++ i) if (i != root) {
        cout << p[i] << " " << i << endl;
    }
    return 0;
}