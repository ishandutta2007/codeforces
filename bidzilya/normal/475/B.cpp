#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int> > used;
string hor, vert;

void dfs(int x, int y)
{
    used[x][y] = 1;
    if (hor[x] == '>') {
        if (y + 1 < m && !used[x][y + 1]) {
            dfs(x, y + 1);
        }
    } else {
        if (y - 1 >= 0 && !used[x][y - 1]) {
            dfs(x, y - 1);
        }
    }
    if (vert[y] == 'v') {
        if (x + 1 < n && !used[x + 1][y]) {
            dfs(x + 1, y);
        }
    } else {
        if (x - 1 >= 0 && !used[x - 1][y]) {
            dfs(x - 1, y);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> hor >> vert;

    bool good = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used.assign(n, vector<int>(m, 0));
            dfs(i, j);
            int sum = 0;
            for (int i1 = 0; i1 < n; ++i1) {
                for (int j1 = 0; j1 < m; ++j1) {
                    sum += used[i1][j1];
                }
            }
            if (sum != n * m) {
                good = false;
            }
        }
    }
    
    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}