#ifndef BICONNECTED_COMPONENTS
#define BICONNECTED_COMPONENTS

// Finding bridges and articulation points in linear time.
// Linear complexity V+E.

#include <vector>
using namespace std;


// This class accepts an undirected graphs and computes its bridges and
// articulation points. The vertices must be 0-based.
// In order to get the articulation point and the bridges, just see the
// BiconnectedComponents.articulation and BiconnectedComponents.bridges.
//
// ACHTUNG: The graph shall not contain multiple edges or self-loops.
struct BiconnectedComponents {
    const int NOT_VISITED = -1;
    int V;
    const vector<int>* aa;  // edges of the graph.
    int current_time;
    vector<int> ot; // Opening time
    // The lowest opening time of a vertex reachable from v without using
    // its father edge.
    vector<int> low;  
    vector<bool> articulation; // Whether a vertex is an articulation point.
    // It stores a pair {u, v} iff it is a a bridge.
    // Each bridge is present only once (i.e. if {u,v} is present; {v, u} is
    // not present).
    vector<pair<int,int>> bridges;
    
    BiconnectedComponents(int V, const vector<int> aa[]) :
            V(V),
            aa(aa),
            current_time(0),
            ot(V, NOT_VISITED),
            low(V),
            articulation(V, false) {
        for (int v = 0; v < V; v++) if (ot[v] == NOT_VISITED) dfs(v, -1);
    }

    // Computes all articulation points and bridges in the connected component
    // of v.
    // father = -1 means that we are calling the dfs for the first time.
    // Deciding whether the root is an articulation point is handled
    // as a special case.
    void dfs(int v, int father) {
        ot[v] = current_time++;
        low[v] = ot[v];
        int sons = 0;
        for (int a : aa[v]) {
            if (a == father) continue;
            if (ot[a] == NOT_VISITED) {
                dfs(a, v);
                sons++;
                if (low[a] == ot[a]) bridges.push_back({v, a});
                if (father != -1 and low[a] >= ot[v]) articulation[v] = true;
            }
            low[v] = min(low[v], low[a]);
        }
        if (father == -1 and sons >= 2) articulation[v] = true;
    }
};

#endif  // BICONNECTED_COMPONENTS


// TODO: TEST!!!

#include <iostream> // TODO: Remove


#ifndef MATROIDS
#define MATROIDS

// Implementation of the matroid intersection algorithm and of various kind of
// classes of matroids (partition, graphic, cographic, linear).

#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
#include <limits>
#include <bitset>
using namespace std;

// Virtual class representing a matroid.
//
// The field n represents the size of the base set, which is assumed to
// be {0, 1, ..., n-1}.
// All subsets of the base set are represented as bitsets (i.e., vector of
// bools so that a certain position is true iff the relative element belongs
// to the subset) because this makes the implementation cleaner without
// worsening the complexity.
// 
// The fundamental method that shall be implemented is antispan, which returns
// the complement of the span of a given subset.
// Even if it is not the most intuitive method to have (is_independent or span
// would be more intuitive), the implementation of the Matroid Intersection
// algorithm is rather neat if antispan is provided.
// For the kind of matroids we provide an implementation of, the antispan
// method is pseudolinear with respect to size of the base set (denoted by n).
//
// Using only antispan, this class offers a number of possibly useful methods:
// span, is_independent, max_independent_subset, rank
struct Matroid {
    int n; // size of the base set
    Matroid(int n): n(n) {}
    
    // Returns the complement of span(S).
    // S is a bitset of size n representing a subset of the base set.
    virtual vector<bool> antispan(const vector<bool>& S) = 0;

    // The following methods offer common operations on a matroid:
    //  - Span
    //  - Independency oracle
    //  - Max independent subset
    //  - Rank
    //
    // All the methods rely only on antispan and may therefore be inefficient.
    // These methods are not called by MatroidIntersection but they may be
    // useful for other purposes.

    // Returns the span of S.
    // Complexity: 1 call to antispan + n.
    vector<bool> span(vector<bool> S) {
        vector<bool> res = antispan(S);
        for (int i = 0; i < n; i++) res[i] = !res[i];
        return res;
    }

    // Whether S is an independent set.
    // Complexity: |S| calls to antispan.
    bool is_independent(vector<bool> S) {
        for (int i = 0; i < n; i++) {
            if (!S[i]) continue;
            S[i] = 0;
            if (!antispan(S)[i]) return false;
            S[i] = 1;
        }
        return true;
    }

    // Returns one of the largest independent subset of S.
    // Complexity: |S| calls to antispan + O(|S|n).
    vector<bool> max_independent_subset(vector<bool> S) {
        // T is an independent subset of S.
        // It is built greedily by adding an element in antispan(T)\cap S.
        vector<bool> T(n, false);
        while (1) {
            vector<bool> antispanT = antispan(T);
            int found = -1;
            for (int i = 0; i < n; i++) {
                if (S[i] and antispanT[i]) {
                    found = i;
                    break;
                }
            }
            if (found < 0) break;
            T[found] = true;
        }
        return T;
    }

    // Returns the rank of S, i.e., the size of its largest independent subset.
    // Complexity: |S| calls to antispan + O(|S|n).
    int rank(vector<bool> S) {
        vector<bool> T = max_independent_subset(S);
        int rk = 0;
        for (int i = 0; i < n; i++) rk += T[i];
        return rk;
    }
};

// This class accepts two matroids on the same base set and solves the relative
// matroid intersection problem.
//
// A and B are the two matroids (instances of the virtual class Matroid).
//
// The set S (represented by a bitset of size n) is one of the subsets of the
// base set with maximum size which is independent with respect to both matroids.
// The constructor takes care of computing S, so that it is immediately
// available. We compute also the dual partitioning of the base set (represented
// by dualA and dualB), which certifies the optimality of S.
//
// Let |S| be the maximum size of a set which is independent with respect to both
// matroids, then the complexity is:
//      O(|S|) calls to antispan + O(|S|n).
struct MatroidIntersection {
    int n;
    Matroid& A;
    Matroid& B;
    // One of the set of maximum size which is independent for A and B.
    vector<bool> S;
    // Two disjoint subsets such that rk_A(dualA) + rk_B(dualB) = |S|.
    // These two sets are a certificate of the optimality for S by the
    // duality theorem for matroid intersection (the easy implication).
    vector<bool> dualA, dualB;
    
    vector<vector<int>> aa;
    vector<int> dist;
    vector<int> bfs_father;
  
    MatroidIntersection(Matroid& A, Matroid& B):
            n(A.n), A(A), B(B), S(n, false), dualA(n, false), dualB(n, false),
            aa(n), dist(n), bfs_father(n) {
        assert(A.n == B.n);
        while(augment()); // At most, |S| calls to augment().
        for (int i = 0; i < n; i++) {
            dualA[i] = dist[i] == numeric_limits<int>::max();
            dualB[i] = dist[i] != numeric_limits<int>::max();
        }
        // These additional checks make O(|S|) calls to antispan, so they
        // should be negligible compared to the algorithm itself and they
        // guarantee its correctness.
        assert(A.is_independent(S) and B.is_independent(S));
        assert(A.rank(S) == A.rank(dualA) + B.rank(dualB));
    }

    bool augment() { // |S|+1 calls to antispan (for each matroid).
        vector<bool> antispanA = A.antispan(S);
        vector<bool> antispanB = B.antispan(S);

        for (int x = 0; x < n; x++) if (antispanA[x] and antispanB[x]) {
            S[x] = 1;
            return true;
        }


        // Building the directed exchange graph.
        for (int x = 0; x < n; x++) aa[x].clear();
        for (int x = 0; x < n; x++) {
            if (!S[x]) continue;
            S[x] = 0;
            vector<bool> new_antispanA = A.antispan(S);
            vector<bool> new_antispanB = B.antispan(S);
            S[x] = 1;
            for (int y = 0; y < n; y++) {
                if (S[y]) continue;
                if (new_antispanA[y]) aa[x].push_back(y);
                if (new_antispanB[y]) aa[y].push_back(x);
            }
        }
        
        bfs(antispanA, antispanB);
        int min_dist = numeric_limits<int>::max();
        for (int x = 0; x < n; x++) {
            if (antispanB[x]) min_dist = min(min_dist, dist[x]);
        }

        // Checking if S is already optimal (i.e., if there is no path from
        // antispanA to antispanB).
        if (min_dist == numeric_limits<int>::max()) return false;

        // Augmenting path.
        for (int x = 0; x < n; x++) {
            if (antispanB[x] and dist[x] == min_dist) {
                int it = x;
                while (it != -1) {
                    S[it] = S[it]^1;
                    it = bfs_father[it];
                }
                break;
            }
        }
        return true;
    }

    // Standard bfs from the set of vertices sources, to the set of vertices
    // sinks.
    // It finds the shortest path from any vertex in sources to any vertex in
    // sinks. For the algorithm to work, the shortest path is necessary and
    // not any path as for matching algorithms.
    void bfs(const vector<bool>& sources, const vector<bool>& sinks) {
        fill(dist.begin(), dist.end(), numeric_limits<int>::max());
        fill(bfs_father.begin(), bfs_father.end(), -1);
        queue<int> q;
        for (int x = 0; x < n; x++) {
            if (sources[x]) {
                dist[x] = 0;
                q.push(x);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: aa[x]) {
                if (dist[y] > dist[x] + 1) {
                    bfs_father[y] = x;
                    dist[y] = dist[x] + 1;
                    if (sinks[y]) return;
                    q.push(y);
                }
            }
        }
    }
};

// Class representing a partition matroid. Each element of the base set (that
// is {0, 1, ..., n-1}) has a label; a set is independent if, for each label x,
// at most multiplicity[x] elements of the set have that label.
// When only one label is present the resulting matroid is called uniform
// matroid.
struct PartitionMatroid:Matroid {
    int labels_num;
    vector<int> label;
    vector<int> multiplicity;

    PartitionMatroid(int n, const vector<int>& label,
                            const vector<int>& multiplicity):
            Matroid(n), labels_num(multiplicity.size()), label(label),
            multiplicity(multiplicity) {
        assert(n == (int)label.size());
        for (int l: label) assert(0 <= l and l < labels_num);
    }

    // Complexity: O(n)
    vector<bool> antispan(const vector<bool>& S) {
        assert(n == (int)S.size());
        vector<int> label_cnt(labels_num, 0);
        for (int i = 0; i < n; i++) if (S[i]) label_cnt[label[i]]++;
        vector<bool> res(n, false);
        for (int i = 0; i < n; i++) {
            res[i] = !S[i] and label_cnt[label[i]] < multiplicity[label[i]];
        }
        return res;
    }
};

// Class representing a graphic matroid. The base set is the set of edges of a
// graph; a set of edges is independent if it forms a forest (i.e., it does not
// contain a cycle).
// An edge is identified by its 0-based position in the vector edges.
//
// The constructor takes the number of vertices V and the edges as a list of
// pairs. The vertices are 0-based.
struct GraphicMatroid:Matroid {
    int V; // number of vertices
    vector<pair<int,int>> edges;
    vector<int> anc;
    GraphicMatroid(int V, const vector<pair<int,int>>& edges):
        Matroid(edges.size()), V(V), edges(edges), anc(V) {
        for (int v = 0; v < V; v++) anc[v] = v;
    }

    // Union-find utilities
    int ancestor(int v) {
        if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
        return anc[v];
    }

    void join(int u, int v) {
        u = ancestor(u);
        v = ancestor(v);
        anc[u] = v;
    }

    // The antispan of a subset S of edges consists of all those edges
    // connecting two vertices which belong to distinct connected components
    // in the graph induced by S.
    //
    // Complexity: O(n\alpha(n))
    vector<bool> antispan(const vector<bool>& S) {
        assert(n == (int)S.size());
        for (int v = 0; v < V; v++) anc[v] = v;
        for (int e = 0; e < n; e++) {
            if (S[e]) join(edges[e].first, edges[e].second);
        }
        vector<bool> res(n, false);
        for (int e = 0; e < n; e++) {
            if (ancestor(edges[e].first) != ancestor(edges[e].second)) {
                res[e] = true;
            }
        }
        return res;
    }
};


// #include "../biconnected_components.cpp"

// Class representing a co-graphic matroid (the dual of a graphic matroid).
// The base set is the set of edges of a graph; a set of edges is independent
// if removing them the graph has the same connectivity it would have with all
// the edges.
// An edge is identified by its 0-based position in the vector edges.
//
// The constructor takes the number of vertices V and the edges as a list of
// pairs. The vertices are 0-based.
//
// ACHTUNG: It uses V memory (it can be avoided using an hash-map for edge2id).
//          Most likely this will never be an issue.
// ACHTUNG: The graph shall not contain multiple edges or self-loops (see
//          biconnected_components.cpp).
struct CoGraphicMatroid:Matroid {
    int V; // number of vertices
    vector<pair<int,int>> edges;
    vector<int> edge2id;
    // We use a pointer for compatibility with BiconnectedComponents.
    vector<int>* aa;
    CoGraphicMatroid(int V, const vector<pair<int,int>>& edges):
        Matroid(edges.size()), V(V), edges(edges), edge2id(V*V) {
        aa = new vector<int>[V];
        for (int e = 0; e < n; e++) edge2id[hash_edge(edges[e])] = e;
    }

    // Fast hash-function: {edges} -> {0, 1, ..., V-1}.
    int hash_edge(pair<int,int> edge) {
        return min(edge.first, edge.second) + V*max(edge.first, edge.second);
    }

    // The antispan of S consists of the non-bridges in the graph induced by the
    // complement of S.
    // Complexity: O(n).
    vector<bool> antispan(const vector<bool>& S) {
        assert(n == (int)S.size());
        for (int v = 0; v < V; v++) aa[v].clear();
        for (int e = 0; e < n; e++) {
            if (!S[e]) {
                int a = edges[e].first;
                int b = edges[e].second;
                aa[a].push_back(b);
                aa[b].push_back(a);
            }
        }
        vector<pair<int,int>> bridges = BiconnectedComponents(V, aa).bridges;

        vector<bool> res(n, true);
        for (int e = 0; e < n; e++) if (S[e]) res[e] = false;
        for (auto bridge: bridges) res[edge2id[hash_edge(bridge)]] = false;
        return res;
    }
};


// Class representing a linear matroid over F_2 (the field with two elements).
// The base set is a set of vectors in F_2^D; a set of vectors is independent
// if it is independent in the vector space.
//
// To save space and time, vectors are represented by bitsets.
template<int D>
struct F2LinearMatroid:Matroid {
    vector<bitset<D>> vec;
    F2LinearMatroid<D>(const vector<bitset<D>>& vec):
        Matroid(vec.size()), vec(vec) {}

    // Complexity: O(nD/64)
    vector<bool> antispan(const vector<bool>& S) {
        vector<bitset<D>> mat;
        for (int i = 0; i < n; i++) if (S[i]) mat.push_back(vec[i]);
        int R = mat.size();
        // We perform the Gaussian algorithm, to make mat a triangular matrix.
        int it = 0;
        vector<int> bits;
        for (int l = 0; l < D; l++) {
            for (int i = it; i < R; i++) {
                if (mat[i][l]) {
                    for (int j = i+1; j < R; j++) if (mat[j][l]) mat[j] ^= mat[i];
                    if (it < i) swap(mat[it], mat[i]);
                    bits.push_back(l);
                    it++;
                    break;
                }
            }
        }
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            if (S[i]) continue;
            bitset<D> x = vec[i];
            for (int j = 0; j < (int)bits.size(); j++)
                if (x[bits[j]]) x ^= mat[j];
            if (x.any()) res[i] = true;
        }
        return res;
    }
};

/*
int main () {
    F2LinearMatroid<5> A({17, 9, 30, 21, 13, 4, 11});
    F2LinearMatroid<5> B({17, 30, 9, 23, 18, 10, 19});
    // PartitionMatroid A(5, {0, 1, 0, 1, 0}, {2, 1});
    // PartitionMatroid B(5, {0, 0, 1, 1, 1}, {1, 2});

    cout << A.n << " " << B.n << endl;

    auto MI = MatroidIntersection(A, B);
    vector<bool> S = MI.S;
    for (int x = 0; x < (int)S.size(); x++) if (S[x]) cout << x << " ";
    cout << endl;

    for (int x = 0; x < A.n; x++) if (MI.dualA[x]) cout << x << " ";
    cout << endl;
    for (int x = 0; x < A.n; x++) if (MI.dualB[x]) cout << x << " ";
    cout << endl;
    // Note to my future self if I don't finish this now.
    // It seems to work, at least MatroidIntersection, F2LinearMatroid and
    // PartitionMatroid.
    // The complexity is good. The usage of bitsets to represent subsets seems
    // to be reasonable and does not worsen the complexity.
    // Using antispan as main method seems reasonable too as it shorten the
    // implementation considerably (compared to using is_independent).
}
*/


const int MAXN = 30;
const int MAXE = 2000;
char mat[MAXN][MAXN];
int cell_id[MAXN][MAXN];
char ans[MAXN*2][MAXN*2];
int black_adj[MAXE];
int from[MAXE];
int toto[MAXE];
vector<int> edges[MAXE];
int E;
int N, M;
int edge_id[MAXE][MAXE];
int xx[MAXE], yy[MAXE];
int free_cells;
 
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
 
 
 
bool visited[MAXN][MAXN];
void easy_visit(int i, int j) {
    visited[i][j] = true;
    for (int t = 0; t < 4; t++) {
        int i1 = i + di[t], j1 = j + dj[t];
        if (i1 < 0 or i1 >= N or j1 < 0 or j1 >= M or mat[i1][j1] == 'X') continue;
        if (!visited[i1][j1]) easy_visit(i1, j1);
    }
}
 
 
#include <bits/stdc++.h>
#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
 
    // #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    // #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        for (int i = 0; i < N*M; i++) edges[i].clear();
        E = 0;
        free_cells = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cell_id[i][j] = -1;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'X') continue;
            if (cell_id[i][j] == -1) {
                cell_id[i][j] = free_cells;
                xx[free_cells] = i, yy[free_cells] = j;
                free_cells++;
            }
            int id0 = cell_id[i][j];
            for (int t = 0; t < 2; t++) {
                int i1 = i + di[t], j1 = j + dj[t];
                if (i1 < 0 or i1 >= N or j1 < 0 or j1 >= M or mat[i1][j1] == 'X') continue;
                if (cell_id[i1][j1] == -1) {
                    cell_id[i1][j1] = free_cells;
                    xx[free_cells] = i1, yy[free_cells] = j1;
                    free_cells++;
                }
                int id1 = cell_id[i1][j1];
                from[E] = id0;
                toto[E] = id1;
                edges[id0].push_back(E);
                edges[id1].push_back(E);
                if ((i+j)%2 == 0) black_adj[E] = id0;
                else black_adj[E] = id1;
                edge_id[id0][id1] = E;
                edge_id[id1][id0] = E;
                E++;
            }
        }
        bool black_leaf = false;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if ((i == 0 and j == 0) or (i+j)%2 or mat[i][j] == 'X') continue;
            if (edges[cell_id[i][j]].size() < 2) black_leaf = true;
        }
        if (black_leaf) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;
        easy_visit(0, 0);
        bool disconnected = false;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (mat[i][j] != 'X' and !visited[i][j]) disconnected = true;
        }
        if (disconnected) {
            cout << "NO\n";
            continue;
        }
 
 
        vector<int> label(E, 0);
        for (int i = 0; i < E; i++) label[i] = black_adj[i];
        vector<int> mult(free_cells, 2);
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (cell_id[i][j] == -1 or (i+j)%2) continue;
            int id = cell_id[i][j];
            mult[id] = ((int)edges[id].size()) - 2;
        }
        mult[0] = 10;
        PartitionMatroid PM(E, label, mult);
 
        vector<pair<int,int>> edges_copy(E);
        for (int i = 0; i < E; i++) edges_copy[i] = {from[i], toto[i]};
        CoGraphicMatroid CM(free_cells, edges_copy);
 
        vector<bool> S = MatroidIntersection(PM, CM).S;
 
        int q = 0;
        for (int i = 0; i < E; i++) q += S[i];
        if (E-q != free_cells-1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < 2*N-1; i++) for (int j = 0; j < 2*M-1; j++) ans[i][j] = ' ';
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            ans[2*i][2*j] = mat[i][j];
            ans[2*i+1][2*j] = '0';
            ans[2*i][2*j+1] = '0';
        }
        for (int i = 0; i < E; i++) {
            if (!S[i]) continue;
            int a = from[i], b = toto[i];
            int x = xx[a];
            int y = yy[a];
            if (x == xx[b]) {
                ans[2*x][2*y+1] = ' ';
            } else {
                ans[2*x+1][2*y] = ' ';
            }
        }
        for (int i = 0; i < 2*N-1; i++) {
            for (int j = 0; j < 2*M-1; j++) cout << ans[i][j];
            cout << "\n";
        }
    }
}
 

#endif // MATROIDS