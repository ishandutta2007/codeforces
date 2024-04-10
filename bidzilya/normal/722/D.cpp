#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_A = 1e9;

const int MAX_LOG = 32;
const int MAX_N = 5e4;

struct TNode {
    int Next[2];
    int Count;
    int Need;
};

const int MAX_NODES_COUNT = MAX_N * MAX_LOG + 1000;

TNode nodes[MAX_NODES_COUNT];
int curNodesCount;

void InitMemory() {
    curNodesCount = 0;
}

void ClearNode(int index) {
    nodes[index].Next[0] = nodes[index].Next[1] = -1;
    nodes[index].Count = 0;
}

int GetNewNode() {
    ClearNode(curNodesCount);
    return curNodesCount++;
}

void Add(int node, const vector<int>& s) {
    for (int i = 0; i < (int) s.size(); ++i) {
        if (nodes[node].Next[s[i]] == -1) {
            nodes[node].Next[s[i]] = GetNewNode();
        }

        node = nodes[node].Next[s[i]];
    }
    ++nodes[node].Count;
}

void FillResult(int node, int value, vector<int>& result, int maxValue) {
    nodes[node].Need = 0;
    for (int id = 0; id < 2; ++id) {
        int nxt = nodes[node].Next[id];

        if (nxt != -1) {
            FillResult(nxt, value * 2 + id, result, maxValue);

            nodes[node].Need += nodes[nxt].Need;
        }
    }
    nodes[node].Need += nodes[node].Count;

    if (value <= maxValue && nodes[node].Need > 0) {
        nodes[node].Need -= 1;
        result.push_back(value);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    InitMemory();

    int root = GetNewNode();

    vector<int> actions;
    actions.reserve(MAX_LOG);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        actions.clear();
        while (x > 1) {
            int y = (x >> 1);

            actions.push_back(x - y * 2);

            x = y;
        }
        reverse(actions.begin(), actions.end());
        Add(root, actions);
    }

    vector<int> result;
    vector<int> buffer;
    buffer.reserve(n);
    int bl = 1;
    int br = MAX_A;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        buffer.clear();

        FillResult(root, 1, buffer, bm);

        if (nodes[root].Need == 0) {
            result = buffer;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    sort(result.begin(), result.end());
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}