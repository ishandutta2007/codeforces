#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m; // number of vertices, number of edges
vector<int> graph[88]; // undirected graph adjacency-list
bool vis[88]; // for DFS

void readInput() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

// push all visited vertices (in the same connected component, i.e.)
// into the passed vector
void dfs(vector<int> & out, int v) {
    if (vis[v]) return;
    vis[v] = true;
    out.push_back(v);
    for (int w : graph[v]) { dfs(out, w); }
}

// groups[i] contains vertex groups of size i
vector<vector<int> > groups[4];

bool fail = false;

void makeGroups() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> vec;
            dfs(vec, i);
            if (vec.size() > 3) {
                fail = true;
                return;
            }
            groups[vec.size()].push_back(vec);
        }
    }
}

void printSolution() {
    // every size-2 group needs one size-1 group to go with it
    if (fail || groups[2].size() > groups[1].size()) {
        printf("-1\n");
    } else {
        for (vector<int> & v : groups[3]) {
            // print size-3 groups
            printf("%d %d %d\n", v[0], v[1], v[2]);
        }
        for (vector<int> & v : groups[2]) {
            // for each size-2 group, pop a size-1 group and print them
            // together
            printf("%d %d %d\n", v[0], v[1], groups[1].back()[0]);
            groups[1].pop_back();
        }
        while (!groups[1].empty()) {
            // pop three size-1 groups and print them
            int v1 = groups[1].back()[0]; groups[1].pop_back();
            int v2 = groups[1].back()[0]; groups[1].pop_back();
            int v3 = groups[1].back()[0]; groups[1].pop_back();
            printf("%d %d %d\n", v1, v2, v3);
        }
    }
}

int main() {
    readInput();
    makeGroups();
    printSolution();
}