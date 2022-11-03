#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const char OCCUPIED = '*';
const char EMPTY = '.';

const int DIR_COUNT = 4;

const int DX[DIR_COUNT] = {-1, 0, 0, 1};
const int DY[DIR_COUNT] = {0, -1, 1, 0};

int n, m;
vector<string> a;

vector<vector<bool>> used;

vector<vector<int>> cmp;

vector<int> square;

vector<bool> isLake;

bool IsGoodPos(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == EMPTY;
}

void Dfs(int i, int j) {
    used[i][j] = true;
    cmp[i][j] = (int) square.size() - 1;
    ++square.back();
    for (int dir = 0; dir < DIR_COUNT; ++dir) {
        int ni = i + DX[dir];
        int nj = j + DY[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
            isLake.back() = false;
        }
        if (IsGoodPos(ni, nj) && !used[ni][nj]) {
            Dfs(ni, nj);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    used.assign(n, vector<bool>(m, false));
    cmp.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && a[i][j] == EMPTY) {
                square.push_back(0);
                isLake.push_back(true);
                Dfs(i, j);
            }
        }
    }

    int lakesCount = 0;
    for (int i = 0; i < (int) square.size(); ++i) {
        if (isLake[i]) {
            ++lakesCount;
        }
    }

    vector<pair<int, int>> temp;
    for (int i = 0; i < (int) square.size(); ++i) {
        if (isLake[i]) {
            temp.push_back(make_pair(square[i], i));
        }
    }

    sort(temp.begin(), temp.end());

    int needDel = lakesCount - k;

    int result = 0;
    for (int i = 0; i < needDel; ++i) {
        result += temp[i].first;
    }

    vector<bool> delCmp(square.size(), false);
    for (int i = 0; i < needDel; ++i) {
        delCmp[temp[i].second] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (delCmp[cmp[i][j]]) {
                a[i][j] = OCCUPIED;
            }
        }
    }

    cout << result << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }
    cout.flush();

    return 0;
}