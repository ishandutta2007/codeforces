#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <cassert>
using namespace std;

struct TNode {
    int AddSum;
    int RightValue;
    int LeftIdx;
    int RightIdx;
};

const int MAX_N = 2e5;
const int MAX_LOG = 20;

const int MAX_NODES_COUNT = MAX_N * MAX_LOG;

TNode nodes[MAX_NODES_COUNT];
int lastNodeIdx;

void Init() {
    lastNodeIdx = 0;
}

int GetNewNode() {
    int idx = lastNodeIdx++;
    nodes[idx].AddSum = 0;
    nodes[idx].RightValue = 0;
    nodes[idx].LeftIdx = -1;
    nodes[idx].RightIdx = -1;
    return idx;
}

int GetRightValue(int node) {
    return node == -1 ? 0 : nodes[node].RightValue;
}

int Add(int oldNode, int tl, int tr, int l, int r, int value) {
    int node = GetNewNode();
    if (oldNode != -1) {
        nodes[node] = nodes[oldNode];
    }
    if (tl == l && tr == r) {
        nodes[node].AddSum += value;
        nodes[node].RightValue += value;
    } else {
        int tm = (tl + tr) >> 1;
        if (r <= tm) {
            nodes[node].LeftIdx = Add(nodes[node].LeftIdx, tl, tm, l, r, value);
        } else if (l > tm) {
            nodes[node].RightIdx = Add(nodes[node].RightIdx, tm + 1, tr, l, r, value);
        } else {
            nodes[node].LeftIdx = Add(nodes[node].LeftIdx, tl, tm, l, tm, value);
            nodes[node].RightIdx = Add(nodes[node].RightIdx, tm + 1, tr, tm + 1, r, value);
        }
        nodes[node].RightValue = GetRightValue(nodes[node].RightIdx) + nodes[node].AddSum;
    }
    return node;
}

int Get(int node, int tl, int tr, int k) {
    if (node == -1) {
        if (k >= 0) {
            return tr;
        } else {
            return -1;
        }
    }
    if (tl == tr) {
        if (nodes[node].RightValue <= k) {
            return tl;
        } else {
            return -1;
        }
    } else {
        k -= nodes[node].AddSum;
        int tm = (tl + tr) >> 1;
        if (GetRightValue(nodes[node].LeftIdx) <= k) {
            int result = Get(nodes[node].RightIdx, tm + 1, tr, k);
            if (result != -1) {
                return result;
            }
            return tm;
        }
        return Get(nodes[node].LeftIdx, tl, tm, k);
    }
}

int n;
vector<int> a;
vector<int> nextPos;

vector<int> trees;

void Solve() {
    nextPos.resize(n);
    {
        map<int, int> lastPos;
        for (int i = n - 1; i >= 0; --i) {
            auto itr = lastPos.find(a[i]);
            if (itr == lastPos.end()) {
                nextPos[i] = -1;
            } else {
                nextPos[i] = itr->second;
            }
            lastPos[a[i]] = i;
        }
    }

    Init();
    trees.resize(n + 1);
    trees[n] = GetNewNode();
    for (int i = n - 1; i >= 0; --i) {
        if (nextPos[i] == -1) {
            trees[i] = Add(trees[i + 1], 0, n - 1, i, n - 1, 1);
        } else {
            trees[i] = Add(trees[i + 1], 0, n - 1, i, nextPos[i] - 1, 1);
        }
    }

    for (int k = 1; k <= n; ++k) {
        int pos = 0;
        int result = 0;
        while (pos < n) {
            int npos = Get(trees[pos], 0, n - 1, k);
            assert(npos >= pos);
            result += 1;
            pos = npos + 1;
        }
        cout << result << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
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