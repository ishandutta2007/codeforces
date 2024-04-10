#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int DIR_COUNT = 4;
const int DX[DIR_COUNT] = {-1, 0, 0, 1};
const int DY[DIR_COUNT] = {0, -1, 1, 0};

const char EMPTY = '.';
const char OCCUP = 'X';

int n, k;
vector<string> field;

int cmpCount;
vector<vector<int>> cmp;
vector<int> cmpSz;

vector<int> usedTime;
int curTime;

vector<vector<pair<int, int>>> ints;

inline bool IsValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void Dfs(int x, int y) {
    cmp[x][y] = cmpCount;
    ++cmpSz[cmpCount];
    for (int dir = 0; dir < DIR_COUNT; ++dir) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];

        if (IsValid(nx, ny) && field[nx][ny] == EMPTY && cmp[nx][ny] == -1) {
            Dfs(nx, ny);
        }
    }
}

void Add(int x, int y) {
    int c = cmp[x][y];
    if (c != -1) {
        ++cmpSz[c];
    }
}

void Del(int x, int y) {
    int c = cmp[x][y];
    if (c != -1) {
        --cmpSz[c];
    }
}

int main() {
//    freopen("input2.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    field.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
    }

    cmpCount = 0;
    cmp.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cmp[i][j] == -1 && field[i][j] == EMPTY) {
                cmpSz.push_back(0);
                Dfs(i, j);
                ++cmpCount;
            }
        }
    }

    int result = 0;
    int curTime = 0;
    usedTime.assign(cmpCount, -1);
    for (int lf = 0; lf + k <= n; ++lf) {
        int rg = lf + k;

        for (int i = 0; i + 1 < k; ++i) {
            for (int j = lf; j < rg; ++j) {
                Del(i, j);
            }
        }

        for (int up = 0; up + k <= n; ++up) {
            int down = up + k;

            for (int j = lf; j < rg; ++j) {
                Del(down - 1, j);
            }

            int curResult = k * k;
            auto addCmp = [&] (int x, int y) {
                int c = cmp[x][y];

                if (c != -1 && usedTime[c] != curTime) {
                    usedTime[c] = curTime;
                    curResult += cmpSz[c];
                }
            };
            for (int j = lf; j < rg; ++j) {
                if (up - 1 >= 0) {
                    addCmp(up - 1, j);
                }
                if (down < n) {
                    addCmp(down, j);
                }
            }
            for (int i = up; i < down; ++i) {
                if (lf - 1 >= 0) {
                    addCmp(i, lf - 1);
                }
                if (rg < n) {
                    addCmp(i, rg);
                }
            }

            for (int j = lf; j < rg; ++j) {
                Add(up, j);
            }

            result = max(result, curResult);
            ++curTime;
        }

        for (int i = n - k + 1; i < n; ++i) {
            for (int j = lf; j < rg; ++j) {
                Add(i, j);
            }
        }
    }

    cout << result << endl;

    return 0;
}