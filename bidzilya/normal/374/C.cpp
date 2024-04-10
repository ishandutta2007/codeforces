#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int max_n = 1e3 + 100;
const int max_v = 1e6 + 100;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int n, m;
char table[max_n][max_n];
vector<vector<int> > g;
int used[max_v];
int cyrcle = 0;
vector<int> len;

int id(int i, int j) {
    return i * m + j;
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u]) {
            dfs(u);
        } else if (used[u] == 1) {
            cyrcle = 1;
        } 
    }
    used[v] = 2;
}

void find_len(int v) {
    len[v] = 1;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u])
            find_len(u);
        len[v] = max(len[v], 1 + len[u]);
    }
}

bool good_symb(char c1, char c2) {
    return c1 == 'D' && c2 == 'I' ||
            c1 == 'I' && c2 == 'M' ||
            c1 == 'M' && c2 == 'A' ||
            c1 == 'A' && c2 == 'D';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            table[i][j] = s[j];
    }
    g.resize(n * m + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && good_symb(table[i][j], table[x][y]))
                    g[id(i, j)].push_back(id(x, y));
            }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (table[i][j] == 'D')
                g[n * m].push_back(id(i, j));
    for (int i = 0; i < n * m; ++i)
        used[i] = 0;
    dfs(n * m);
    if (cyrcle) {
        cout << "Poor Inna!" << endl;
        return 0;
    } 
    for (int i = 0; i < n * m; ++i)
        used[i] = 0;
    len.resize(n * m + 1);
    find_len(n * m);
    int cur_len = (len[n * m] - 1) / 4;
    if (cur_len == 0) {
        cout << "Poor Dima!" << endl;
    } else {
        cout << cur_len << endl;
    }
    return 0;
}