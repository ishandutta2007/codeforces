#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int REM = 1e9 + 7;
 
vector<vector<int>> adj;
bool dfs(int node, int col[], int color) {
    col[node] = color;
 
    for (int nbr : adj[node]) {
        if (col[nbr] == 0) {
            bool subres = dfs(nbr, col, 3 - color);
        } else if (col[nbr] == col[node]) {
            return true;
        }
    }
 
    return false;
}
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << std::fixed;
    cout << std::setprecision(10);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n);
        bool flag = true;
 
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
 
        for (int i = 0; i < n; i++) {
            if ((int)adj[i].size() > 2) {
                flag = false;
                break;
            }
        }
 
        if (flag == false) {
            cout << "NO" << "\n";
            continue;
        }
 
        int col[n] = {0};
        for (int i = 0; i < n; i++) {
            if (col[i] == 0) {
                bool res = dfs(i, col, 1);
                if (res == true) {
                    flag = false;
                    break;
                }
            }
        }
 
        if (flag == false) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
 
    return 0;
}