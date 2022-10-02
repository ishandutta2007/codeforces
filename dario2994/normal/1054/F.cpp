#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Container>
int SZ(const Container& S) { return S.size(); }

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

#ifndef MAXIMUM_MATCHING
#define MAXIMUM_MATCHING

// Fold-Fulkerson implementation to find maximum matching in a bipartite graph.
// Complexity VE (it performs faster on real graph).
//
// The implementation splits the bipartite graph (and all the helper data
// structures) in two parts, called left and right.

#include <vector>
using namespace std;

vector<bool> left_doneX;
vector<bool> right_doneX;

class MaximumMatching {
  public:
    const static int NOT_MATCHED = -1;
    // The edges vector stores the edges that goes from left to right.
    MaximumMatching(int left_num, int right_num, const vector<vector<int>>& edges) :
            left_num(left_num),
            right_num(right_num),
            edges(edges),
            computed_matching(false),
            matching_size(0),
            left2right(left_num, NOT_MATCHED),
            right2left(right_num, NOT_MATCHED) {}

    // Get matching size.
    int GetSize() {
        ComputeMaximumMatching();
        return matching_size;
    }

    vector<int> GetMatching() {
        ComputeMaximumMatching();
        return left2right;
    }
    int left_num;
    int right_num;
    // Edges go from left vertices to right vertices.
    const vector<vector<int>>& edges;  // Not owned.
    // Whether the matching has already been computed.
    bool computed_matching;
    int matching_size;
    // If the a-th left vertex is matched to the b-th right then
    // left2right[a] = b. If the a-th left vertex is not matched to any
    // right vertex then left2right[a] = NOT_MATCHED.
    // The same (inverting left and right) is true for right2left.
    vector<int> left2right;  // size = left_num.
    vector<int> right2left;  // size = right_num.

    // Tries to find an augmenting path starting from the left vertex v.
    // Returns true if it has found an augmenting path, false otherwise.
    bool FindAugmentingPath(
            int v, vector<bool>& left_done, vector<bool>& right_done){
        if (left_done[v]) return false;
        left_done[v] = true;

        for (int a : edges[v]) {
            if (right_done[a] or left2right[v] == a) continue;
            right_done[a] = true;

            if (right2left[a] == NOT_MATCHED ||
                FindAugmentingPath(right2left[a], left_done, right_done)) {
                right2left[a] = v;
                left2right[v] = a;
                return true;
            }
        }
        return false;
    }

    // Computes the maximum matching and stores the result in left2right and
    // right2left.
    void ComputeMaximumMatching() {
        if (computed_matching) return;
        left_doneX.resize(left_num, false);
        right_doneX.resize(right_num, false);
        bool matching_augmented = true;
        while (matching_augmented) {
            matching_augmented = false;
            fill(left_doneX.begin(), left_doneX.end(), false);
            fill(right_doneX.begin(), right_doneX.end(), false);
            for (int v = 0; v < left_num; v++) {
                if (left2right[v] == NOT_MATCHED) {
                    bool updated = FindAugmentingPath(v, left_doneX, right_doneX);
                    matching_augmented |= updated;
                    matching_size += updated;
                }
            }
        }
        computed_matching = true;
    }
};

const int MaximumMatching::NOT_MATCHED;  // Needed for the linker.

#endif  // MAXIMUM_MATCHING



///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<pair<int,int>> P(N);
    map<int,map<int,int>> row, col;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
        row[P[i].second][P[i].first] = i;
        col[P[i].first][P[i].second] = i;
    }
    vector<pair<int,int>> lseg, rseg;
    for (auto& pp : row) {
        auto& mp = pp.second;
        vector<int> vec;
        for (auto pp2 : mp) vec.push_back(pp2.second);
        for (int i = 0; i < (int)vec.size()-1; i++) lseg.push_back({vec[i], vec[i+1]});
    }
    for (auto& pp : col) {
        auto& mp = pp.second;
        vector<int> vec;
        for (auto pp2 : mp) vec.push_back(pp2.second);
        for (int i = 0; i < (int)vec.size()-1; i++) rseg.push_back({vec[i], vec[i+1]});
    }
    int L = lseg.size();
    int R = rseg.size();
    vector<vector<int>> aa(L);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            if (P[lseg[i].first].first < P[rseg[j].first].first and P[rseg[j].first].first < P[lseg[i].second].first and
                P[rseg[j].first].second < P[lseg[i].first].second and P[lseg[i].first].second < P[rseg[j].second].second) {
                aa[i].push_back(j);
            }
        }
    }
    // dbg_var(lseg);
    // dbg_var(rseg);
    // dbg_var(aa);
    MaximumMatching mm(L, R, aa);
    mm.GetSize();
    vector<bool> hor_nostart(N), ver_nostart(N);
    for (int i = 0; i < L; i++) {
        if (left_doneX[i]) {
            // cout << "L" << " " << i << endl;
            hor_nostart[lseg[i].second] = true;
        }
    }
    for (int i = 0; i < R; i++) {
        if (!right_doneX[i]) {
            // cout << "R" << " " << i << endl;
            ver_nostart[rseg[i].second] = true;
        }
    }

    vector<pair<int,int>> ansh, ansv;
    for (auto& pp : row) {
        auto& mp = pp.second;
        vector<int> vec;
        for (auto pp2 : mp) vec.push_back(pp2.second);
        // dbg_var(vec);
        int curr = -1;
        for (int i = 0; i < (int)vec.size(); i++) {
            if (!hor_nostart[vec[i]]) {
                if (curr != -1) ansh.push_back({curr, vec[i-1]});
                curr = vec[i];
            }
        }
        ansh.push_back({curr, vec.back()});
    }
    // dbg_var(hor_nostart);
    // dbg_var(ansh);
    for (auto& pp : col) {
        auto& mp = pp.second;
        vector<int> vec;
        for (auto pp2 : mp) vec.push_back(pp2.second);
        // dbg_var(vec);
        int curr = -1;
        for (int i = 0; i < (int)vec.size(); i++) {
            if (!ver_nostart[vec[i]]) {
                if (curr != -1) ansv.push_back({curr, vec[i-1]});
                curr = vec[i];
            }
        }
        ansv.push_back({curr, vec.back()});
    }
    // dbg_var(ver_nostart);
    // dbg_var(ansv);
    cout << ansh.size() << "\n";
    for (auto pp : ansh) {
        cout << P[pp.first].first << " " << P[pp.first].second << " " << P[pp.second].first << " " << P[pp.second].second << "\n";
    }
    cout << ansv.size() << "\n";
    for (auto pp : ansv) {
        cout << P[pp.first].first << " " << P[pp.first].second << " " << P[pp.second].first << " " << P[pp.second].second << "\n";
    }
}