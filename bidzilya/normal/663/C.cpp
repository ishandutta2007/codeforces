#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TEdge {
    int From;
    int To;
    char Color;
};

int n;
vector<vector<TEdge>> g;

struct TResult {
    vector<int> Values;
    bool Found;
};

TResult result;

vector<int> cmp;
vector<vector<int>> cmpVs;
int cmpCount;

void BuildCmpDfs(int v) {
    cmp[v] = cmpCount;
    for (const TEdge& e : g[v]) {
        if (cmp[e.To] == -1) {
            BuildCmpDfs(e.To);
        }
    }
}

void BuildCmp() {
    cmp.assign(n, -1);
    cmpCount = 0;
    for (int i = 0; i < n; ++i) {
        if (cmp[i] == -1) {
            BuildCmpDfs(i);
            ++cmpCount;
        }
    }
    cmpVs.resize(cmpCount);
    for (int i = 0; i < n; ++i) {
        cmpVs[cmp[i]].push_back(i);
    }
}

void UpdateResult(TResult& result, const TResult& curResult) {
    if (!curResult.Found) {
        return;
    }
    if (!result.Found || curResult.Values.size() < result.Values.size()) {
        result.Found = true;
        result.Values = curResult.Values;
    }
}

bool SolveDfs(int v, vector<int>& used, int needUse, char needColor) {
    if (used[v] == -1) {
        used[v] = needUse;
    } else {
        return used[v] == needUse;
    }
    for (const TEdge& e : g[v]) {
        if (e.Color == needColor) {
            if (!SolveDfs(e.To, used, needUse, needColor)) {
                return false;
            }
        } else {
            if (!SolveDfs(e.To, used, 1 - needUse, needColor)) {
                return false;
            }
        }
    }
    return true;
}

void Solve(char needColor) {
    TResult curResult;
    curResult.Found = true;

    vector<int> used(n, -1);

    vector<bool> usedCmp(cmpCount, false);
    for (int i = 0; i < n; ++i) {
        if (usedCmp[cmp[i]]) {
            continue;
        }

        usedCmp[cmp[i]] = true;

        TResult curCmpResult;
        curCmpResult.Found = false;
        for (int j = 0; j < 2; ++j) {
            for (int v : cmpVs[cmp[i]]) {
                used[v] = -1;
            }
            if (SolveDfs(i, used, j, needColor)) {
                TResult buf;
                buf.Found = true;
                for (int v : cmpVs[cmp[i]]) {
                    if (used[v] == 1) {
                        buf.Values.push_back(v);
                    }
                }
                UpdateResult(curCmpResult, buf);
            }
        }

        if (!curCmpResult.Found) {
            return;
        }

        for (int x : curCmpResult.Values) {
            curResult.Values.push_back(x);
        }
    }

    UpdateResult(result, curResult);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int m;
    cin >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        char c;
        cin >> v1 >> v2 >> c;
        --v1;
        --v2;
        g[v1].push_back(TEdge{v1, v2, c});
        g[v2].push_back(TEdge{v2, v1, c});
    }

    result.Found = false;

    BuildCmp();

    for (char color : {'B', 'R'}) {
        Solve(color);
    }

    if (!result.Found) {
        cout << -1 << endl;
    } else {
        sort(result.Values.begin(), result.Values.end());
        cout << result.Values.size() << endl;
        for (int i : result.Values) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}