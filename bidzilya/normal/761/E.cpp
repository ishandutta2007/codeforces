#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const int DOWN = 0;
const int UP = 1;
const int LEFT = 2;
const int RIGHT = 3;

int GetOpposite(int dir) {
    if (dir == -1) {
        return -1;
    } else if (dir == DOWN) {
        return UP;
    } else if (dir == UP) {
        return DOWN;
    } else if (dir == LEFT) {
        return RIGHT;
    } else if (dir == RIGHT) {
        return LEFT;
    } else {
        assert(false);
    }
}

const long long INF = 1e18;

const string NO = "NO";
const string YES = "YES";

int n;
vector<vector<int>> g;

vector<pair<long long, long long>> result;

void BuildResult(int v, int prevDir, int pr,
    pair<long long, long long> xBorders,
    pair<long long, long long> yBorders)
{
    vector<int> childs;
    for (int u : g[v]) {
        if (u != pr) {
            childs.push_back(u);
        }
    }

    const long long xLen = (xBorders.second - xBorders.first + 1) / 3;
    const long long xFirst = xBorders.first + xLen;
    const long long xSecond = xBorders.second - xLen;

    const long long yLen = (yBorders.second - yBorders.first + 1) / 3;
    const long long yFirst = yBorders.first + yLen;
    const long long ySecond = yBorders.second - yLen;

    result[v].first = (xFirst + 1 + xSecond) / 2;
    result[v].second = (yFirst + 1 + ySecond) / 2;
    if (pr != -1) {
        if (prevDir == UP || prevDir == DOWN) {
            result[v].first = result[pr].first;
        }
        if (prevDir == LEFT || prevDir == RIGHT) {
            result[v].second = result[pr].second;
        }
    }

    vector<int> dir;
    vector<pair<long long, long long>> xb;
    vector<pair<long long, long long>> yb;

    prevDir = GetOpposite(prevDir);

    if (prevDir != LEFT) {
        dir.push_back(LEFT);
        xb.push_back(make_pair(xBorders.first, xFirst));
        yb.push_back(make_pair(yFirst + 1, ySecond));
    }

    if (prevDir != UP) {
        dir.push_back(UP);
        xb.push_back(make_pair(xFirst + 1, xSecond));
        yb.push_back(make_pair(ySecond + 1, yBorders.second));
    }

    if (prevDir != DOWN) {
        dir.push_back(DOWN);
        xb.push_back(make_pair(xFirst + 1, xSecond));
        yb.push_back(make_pair(yBorders.first, yFirst));
    }

    if (prevDir != RIGHT) {
        dir.push_back(RIGHT);
        xb.push_back(make_pair(xSecond + 1, xBorders.second));
        yb.push_back(make_pair(yFirst + 1, ySecond));
    }

    for (int u : childs) {
        BuildResult(u, dir.back(), v, xb.back(), yb.back());
        dir.pop_back();
        xb.pop_back();
        yb.pop_back();
    }
}

void Solve() {
    for (int i = 0; i < n; ++i) {
        int d = g[i].size();
        if (d > 4) {
            cout << NO << endl;
            return;
        }
    }
    result.resize(n);
    BuildResult(0, -1, -1, make_pair(-INF, INF), make_pair(-INF, INF));
    cout << YES << endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i].first << " " << result[i].second << endl;
    }
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}