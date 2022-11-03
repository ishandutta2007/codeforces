#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
using namespace std;

#define next nealksjd

int r, c;
vector<vector<int>> table;

vector<vector<int>> strComp;
vector<vector<int>> stlComp;

using TId = pair<int, int>;

vector<pair<TId, int>> elems;

bool Cmp(const pair<TId, int>& lhs, const pair<TId, int>& rhs) {
    return lhs.second < rhs.second;
}

int n;
vector<int> head;
vector<int> next;
vector<int> data;

vector<int> revHead;
vector<int> revNext;
vector<int> revData;

void Init() {
    n = 0;
    head.reserve(2 * r * c);
    next.reserve(4 * r * c);
    data.reserve(4 * r * c);
}

int AddNewVertex() {
    head.push_back(-1);
    return n++;
}

void AddNewEdge(int v1, int v2) {
    next.push_back(head[v1]);
    data.push_back(v2);
    head[v1] = next.size() - 1;
}

void BuildComp(vector<vector<int>>& ids) {
    sort(elems.begin(), elems.end(), Cmp);
    int comp;
    for (int i = 0; i < (int) elems.size(); ++i) {
        if (i == 0 || elems[i - 1].second != elems[i].second) {
            comp = AddNewVertex();
        }
        ids[elems[i].first.first][elems[i].first.second] = comp;
    }
    for (int i = 1; i < (int) elems.size(); ++i) {
        if (elems[i].second != elems[i - 1].second) {
            int prevComp = ids[elems[i - 1].first.first][elems[i - 1].first.second];
            int curComp = ids[elems[i].first.first][elems[i].first.second];

            AddNewEdge(prevComp, curComp);
        }
    }
}

void BuildAllComp() {
    Init();

    strComp.resize(r, vector<int>(c));
    stlComp.resize(r, vector<int>(c));

    elems.resize(c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            elems[j].first = make_pair(i, j);
            elems[j].second = table[i][j];
        }
        BuildComp(strComp);
    }

    elems.resize(r);
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            elems[i].first = make_pair(i, j);
            elems[i].second = table[i][j];
        }
        BuildComp(stlComp);
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            AddNewEdge(strComp[i][j], stlComp[i][j]);
            AddNewEdge(stlComp[i][j], strComp[i][j]);
        }
    }
}

void AddRevEdge(int v1, int v2) {
    revNext.push_back(revHead[v1]);
    revData.push_back(v2);
    revHead[v1] = revNext.size() - 1;
}

void BuildRev() {
    revHead.assign(n, -1);
    revNext.reserve(next.size());
    revData.reserve(data.size());
    for (int i = 0; i < n; ++i) {
        for (int j = head[i]; j != -1; j = next[j]) {
            int k = data[j];
            AddRevEdge(k, i);
        }
    }
}

vector<int> top;
vector<bool> used;

vector<int> comp;
int compCount;

void BuildTopSort(int v) {
    used[v] = true;
    for (int i = head[v]; i != -1; i = next[i]) {
        int u = data[i];
        if (!used[u]) {
            BuildTopSort(u);
        }
    }
    top.push_back(v);
}

void Dfs(int v) {
    comp[v] = compCount;
    used[v] = true;
    for (int i = revHead[v]; i != -1; i = revNext[i]) {
        int u = revData[i];
        if (!used[u]) {
            Dfs(u);
        }
    }
}

void Compress() {
    top.reserve(n);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            BuildTopSort(i);
        }
    }
    reverse(top.begin(), top.end());
    BuildRev();
    comp.resize(n);
    compCount = 0;
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        int v = top[i];
        if (!used[v]) {
            Dfs(v);
            ++compCount;
        }
    }
}

vector<int> compHead;
vector<int> compNext;
vector<int> compData;

void AddCompEdge(int v1, int v2) {
    compNext.push_back(compHead[v1]);
    compData.push_back(v2);
    compHead[v1] = compNext.size() - 1;
}

void BuildComp() {
    compHead.assign(compCount, -1);
    compNext.reserve(next.size());
    compData.reserve(data.size());

    for (int v = 0; v < n; ++v) {
        for (int i = head[v]; i != -1; i = next[i]) {
            int u = data[i];

            int cv = comp[v];
            int cu = comp[u];

            if (cv != cu) {
                AddCompEdge(cv, cu);
            }
        }
    }
}

vector<int> compTop;

void BuildCompTop(int v) {
    used[v] = true;
    for (int i = compHead[v]; i != -1; i = compNext[i]) {
        int u = compData[i];
        if (!used[u]) {
            BuildCompTop(u);
        }
    }
    compTop.push_back(v);
}

vector<int> values;

void FillValues() {
    BuildComp();
    compTop.reserve(compCount);
    used.assign(compCount, false);
    for (int i = 0; i < compCount; ++i) {
        if (!used[i]) {
            BuildCompTop(i);
        }
    }
    reverse(compTop.begin(), compTop.end());
    values.assign(compCount, 1);
    for (int i = 0; i < compCount; ++i) {
        int v = compTop[i];
        for (int j = compHead[v]; j != -1; j = compNext[j]) {
            int u = compData[j];

            values[u] = max(values[u], values[v] + 1);
        }
    }
}

void FillTable() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            table[i][j] = values[comp[strComp[i][j]]];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d%d", &r, &c);

    table.resize(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &table[i][j]);
        }
    }

    BuildAllComp();

    Compress();

    FillValues();

    FillTable();

    /*
    cout << n << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << strComp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << stlComp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int v = 0; v < n; ++v) {
        for (int i = head[v]; i != -1; i = next[i]) {
            int u = data[i];
            
            cout << "(" << v << ", " << u << ")" << endl;
        }
    }
    cout << endl;
    */

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}