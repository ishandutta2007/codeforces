#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

class DisjointSets {
    private:
        vector<int> parents;
        vector<int> sizes;
    public:
        DisjointSets(int size) : parents(size), sizes(size, 1) {
            for (int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }

        int get_ultimate(int n) {
            return parents[n] == n ? n : (parents[n] = get_ultimate(parents[n]));
        }

        bool link(int n1, int n2) {
            n1 = get_ultimate(n1);
            n2 = get_ultimate(n2);
            if (n1 == n2) {
                return false;
            }
            if (sizes[n1] < sizes[n2]) {
                std::swap(n1, n2);
            }
            sizes[n1] += sizes[n2];
            parents[n2] = n1;
            return true;
        }
};

/**
 * https://codeforces.com/contest/472/problem/D
 * 3
 * 0 2 7
 * 2 0 9
 * 7 9 0 should output YES
 */
int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int node_num;
    std::cin >> node_num;
    vector<vector<int>> dists(node_num, vector<int>(node_num));
    vector<pair<int, int>> edges;
    for (int n1 = 0; n1 < node_num; n1++) {
        for (int n2 = 0; n2 < node_num; n2++) {
            std::cin >> dists[n1][n2];
            edges.push_back({n1, n2});
        }
    }

    std::sort(
        edges.begin(), edges.end(),
        [&] (const pair<int, int>& a, const pair<int, int>& b) {
            return dists[a.first][a.second] < dists[b.first][b.second];
        }
    );
    DisjointSets tree(node_num);
    vector<vector<int>> neighbors(node_num);
    vector<vector<int>> calculated(node_num, vector<int>(node_num, INT32_MAX));
    for (const pair<int, int>& e : edges) {
        if (dists[e.first][e.second] > 0
                && tree.get_ultimate(e.first) != tree.get_ultimate(e.second)) {
            tree.link(e.first, e.second);
            calculated[e.first][e.second] = dists[e.first][e.second];
            calculated[e.second][e.first] = dists[e.first][e.second];
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
        }
    }

    for (int start = 0; start < node_num; start++) {
        calculated[start][start] = 0;
        std::deque<int> frontier{start};
        vector<bool> visited(node_num);
        visited[start] = true;
        while (!frontier.empty()) {
            int curr = frontier.front();
            frontier.pop_front();
            for (int n : neighbors[curr]) {
                if (!visited[n]) {
                    visited[n] = true;
                    frontier.push_back(n);
                    calculated[start][n] = calculated[start][curr] + calculated[curr][n];
                }
            }
        }
    }
    cout << (calculated == dists ? "YES" : "NO") << endl;
}