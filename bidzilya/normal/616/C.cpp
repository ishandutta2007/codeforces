#include <iostream>
#include <vector>
#include <string>

#include <cstdio>
using namespace std;

const int MOD = 10;
const char EMPTY = '.';

vector<vector<bool>> used;
vector<vector<int>> color;
vector<int> compSize;

int n, m;
vector<string> table;

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

void Dfs(int x, int y, int c) {
    color[x][y] = c;
    ++compSize[c];
    used[x][y] = true;
    for (int k = 0; k < 4; ++k) {
        int nx = x + DX[k];
        int ny = y + DY[k];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && (table[nx][ny] == EMPTY)) {
            Dfs(nx, ny, c);
        }
    }
}

const int BUFFER_LEN = 1111;

char BUFFER[BUFFER_LEN];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d%d", &n, &m);
    used.assign(n, vector<bool>(m, false));
    color.resize(n, vector<int>(m));
    table.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", BUFFER);
        table[i] = BUFFER;
    }

    int lastColor = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && table[i][j] == EMPTY) {
                compSize.push_back(0);
                Dfs(i, j, lastColor++);
            }
        }
    }

    vector<int> compUsed(lastColor, false);
    for (int i = 0; i < n; ++i) {
        string result;
        result.resize(m);
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == EMPTY) {
                result[j] = EMPTY;
            } else {
                int count = 1;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + DX[k];
                    int nj = j + DY[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && (table[ni][nj] == EMPTY) && !compUsed[color[ni][nj]]) {
                        compUsed[color[ni][nj]] = true;
                        count += compSize[color[ni][nj]];
                    }
                }
                for (int k = 0; k < 4; ++k) {
                    int ni = i + DX[k];
                    int nj = j + DY[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && (table[ni][nj] == EMPTY)) {
                        compUsed[color[ni][nj]] = false;
                    }
                }
                result[j] = (char)((count % MOD) + '0');
            }
        }
        printf("%s\n", result.c_str());
    }

    return 0;
}