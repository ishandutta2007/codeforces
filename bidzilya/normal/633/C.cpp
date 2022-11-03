#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cassert>
using namespace std;

char ToSmall(char c) {
    if (c >= 'a' && c <= 'z') {
        return c;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    assert(false);
}

const int MAX_C = 26;

struct TNode {
    vector<int> Next;
    int IndexEnd;
};

const int MAX_NODE_COUNT = 1e6 + 100;

TNode Nodes[MAX_NODE_COUNT];
int nodeCount;

void Clear(int node) {
    Nodes[node].Next.assign(MAX_C, -1);
    Nodes[node].IndexEnd = -1;
}

int GetNewNode() {
    Clear(nodeCount);
    return nodeCount++;
}

void Init() {
    GetNewNode();
    nodeCount = 1;
}

void AddString(const string& s, int index) {
    int n = s.length();
    int node = 0;
    for (int i = 0; i < n; ++i) {
        int c = ToSmall(s[i]) - 'a';

        if (Nodes[node].Next[c] == -1) {
            Nodes[node].Next[c] = GetNewNode();
        }

        node = Nodes[node].Next[c];
    }
    Nodes[node].IndexEnd = index;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    Init();

    int m;
    cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
        AddString(t[i], i);
    }

    vector<int> dp(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        int node = 0;
        for (int j = i; j < n; ++j) {
            int c = s[j] - 'a';

            if (Nodes[node].Next[c] != -1) {
                node = Nodes[node].Next[c];

                if (Nodes[node].IndexEnd != -1 && (j + 1 == n || dp[j + 1] != -1)) {
                    dp[i] = Nodes[node].IndexEnd;
                    break;
                }
            } else {
                break;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i < n; ) {
        result.push_back(dp[i]);
        i += t[dp[i]].length();
    }

    reverse(result.begin(), result.end());
    for (int i = 0; i < (int) result.size(); ++i) {
        cout << t[result[i]];
        if (i + 1 != result.size()) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}