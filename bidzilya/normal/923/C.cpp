#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const int MAX_N = 3e5;
const int BITS_COUNT = 30;

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

struct TNode {
    int Next[2];
    int Count;

    void Clear() {
        Next[0] = Next[1] = -1;
        Count = 0;
    }
};

const int NODES_LIM = 2 * BITS_COUNT * MAX_N + 1;

TNode nodes[NODES_LIM];
int nodesCount;

void InitNodes() {
    nodesCount = 1;
    nodes[0].Clear();
}

int GetNewNode() {
    nodes[nodesCount].Clear();
    return nodesCount++;
}

bool ExistsChild(int root, int idx) {
    return nodes[root].Next[idx] != -1 && nodes[nodes[root].Next[idx]].Count > 0;
}

int GetChild(int root, int idx) {
    if (nodes[root].Next[idx] == -1) {
        nodes[root].Next[idx] = GetNewNode();
    }
    return nodes[root].Next[idx];
}

void AddImpl(int root, int value, int count) {
    nodes[root].Count += count;
    for (int b = BITS_COUNT - 1; b >= 0; --b) {
        const int x = GetBit(value, b);
        const int nxt = GetChild(root, x);
        nodes[nxt].Count += count;
        root = nxt;
    }
}

void Add(int root, int value) {
    AddImpl(root, value, 1);
}

void Remove(int root, int value) {
    AddImpl(root, value, -1);
}

int GetMin(int root, int value) {
    int result = 0;
    for (int b = BITS_COUNT - 1; b >= 0; --b) {
        const int x = GetBit(value, b);
        const int y = (ExistsChild(root, x) ? x : 1 - x);
        result |= (y << b);
        root = GetChild(root, y);
    }
    return result;
}

int n;
vector<int> a;
vector<int> p;

void Solve() {
    InitNodes();

    for (int i = 0; i < n; ++i) {
        Add(0, p[i]);
    }

    for (int i = 0; i < n; ++i) {
        int x = GetMin(0, a[i]);
        cout << (x ^ a[i]) << " ";
        Remove(0, x);
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
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}