/*
  !










*/
#include <unordered_map>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define int int64_t
#define all(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair

void dfs(const vector<vector<int>> &graph, int vert, vector<int> &used, int num)
{
    used[vert] = num;
    for (int elem : graph[vert]) {
        //cout << vert << " : " << elem << endl;
        if (!used[elem])
            dfs(graph, elem, used, num);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }

    vector<int> colors(n);
    unordered_map<int, int> counter;
    int color = 1;
    for (int i = 0; i < n; ++i) {
        if (!colors[i]) {
            dfs(graph, i, colors, color);
            color++;
        }
    }
    for (int i = 0; i < n; ++i) {
        counter[colors[i]]++;
    }

    /*for (int i = 0; i < n; ++i) {
        cout << colors[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << counter[colors[i]] << " ";
    }
    cout << endl;*/

    for (int i = 0; i < n; ++i) {
        if (graph[i].size() != counter[colors[i]] - 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}