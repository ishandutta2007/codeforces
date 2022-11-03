#include <iostream>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 3e5 + 100;

const int MAX_C = 26;

struct Node
{
    int next[MAX_C];
    int count;

    Node()
    {
        fill(next, next + MAX_C, -1);
        count = 0;
    }
};

int n;
int c[MAX_N];
long long ans[MAX_N];

string s;
vector<vector<int>> g;

const int MAX_NODE_COUNT = 3e5 + 100;

Node nodes[MAX_NODE_COUNT];
int nodeCount;

int nodeIndex[MAX_N];

int Merge(int lhs, int rhs)
{
    for (int i = 0; i < MAX_C; ++i) {
        if (nodes[lhs].next[i] == -1) {
            if (nodes[rhs].next[i] != -1) {
                nodes[lhs].next[i] = nodes[rhs].next[i];
                nodes[lhs].count += nodes[nodes[rhs].next[i]].count;
            }
        } else {
            if (nodes[rhs].next[i] != -1) {
                nodes[lhs].count -= nodes[nodes[lhs].next[i]].count;
                nodes[lhs].next[i] = Merge(nodes[lhs].next[i], nodes[rhs].next[i]);
                nodes[lhs].count += nodes[nodes[lhs].next[i]].count;
            }
        }
    }
    return lhs;
}

void Dfs(int v, int pr)
{
    for (int i : g[v]) {
        if (i == pr) {
            continue;
        }
        Dfs(i, v);
    }
    nodeIndex[v] = nodeCount++;
    Node& root = nodes[nodeIndex[v]];
    for (int i : g[v]) {
        if (i == pr) {
            continue;
        }
        if (root.next[s[i] - 'a'] == -1) {
            root.next[s[i] - 'a'] = nodeIndex[i];
        } else {
            root.count -= nodes[root.next[s[i] - 'a']].count;
            root.next[s[i] - 'a'] = Merge(root.next[s[i] - 'a'], nodeIndex[i]);
        }
        root.count += nodes[root.next[s[i] - 'a']].count;
    }
    root.count += 1;
    ans[v] = root.count;
}

void ShowAns()
{
    for (int i = 0; i < n; ++i) {
        ans[i] += c[i];
    }
    long long ansValue = ans[0];
    int ansCount = 1;
    for (int i = 1; i < n; ++i) {
        if (ans[i] == ansValue) {
            ++ansCount;
        } else if (ans[i] > ansValue) {
            ansValue = ans[i];
            ansCount = 1;
        }
    }
    cout << ansValue << endl;
    cout << ansCount << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    cin >> s;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    nodeCount = 0;
    Dfs(0, -1);

    ShowAns();

    return 0;
}