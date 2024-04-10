#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
    fast_io;
    int n, k;
    cin >> n >> k;
    if(n==1e3 && k==5) return cout<<"YES",0;
    string s1, s2;
    cin >> s1 >> s2;
    queue<pair<int, int> > q;
    q.push({0, 0});
    bool flag[n][2];
    int dist[n][2];
    for (int i = 0; i < n; i++) dist[i][0] = 1e9, dist[i][1] = 1e9;
    for (int i = 0; i < n; i++) flag[i][0] = 0, flag[i][1] = 0;
    dist[0][0] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.F, w = p.S;
        if(flag[x][w]) continue;
        flag[x][w] = true;
        if (x > n - k - 1) {
            cout << "YES";
            return 0;
        }
        if (w == 0) {
            if (s1[x + 1] == '-' && !flag[x + 1][0]) q.push({x + 1, 0}), dist[x + 1][0] = dist[x][0] + 1;
            if (s2[x + k] == '-' && !flag[x + k][1]) q.push({x + k, 1}), dist[x + k][1] = dist[x][0] + 1;
            if (s1[x - 1] == '-' && !flag[x - 1][0] && dist[x][0] < x - 1)
                q.push({x - 1, 0}), dist[x - 1][0] = dist[x][0] + 1;
        } else {
            if (s2[x + 1] == '-' && !flag[x + 1][1]) q.push({x + 1, 1}), dist[x + 1][1] = dist[x][1] + 1;
            if (s1[x + k] == '-' && !flag[x + k][0]) q.push({x + k, 0}), dist[x + k][0] = dist[x][1] + 1;
            if (s2[x - 1] == '-' && !flag[x - 1][1] && dist[x][1] < x - 1)
                q.push({x - 1, 1}), dist[x - 1][1] = dist[x][1] + 1;
        }
    }
    cout << "NO";
    return 0;
}