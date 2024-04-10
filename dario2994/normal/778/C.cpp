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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) cout << #x  << ": " << x << endl;
    #define dbg_vec(x) cout << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) cout << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif  

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// Inizio: 17.00, fine 17.31, fine debug 

struct Node {
    Node* children[26];
    bool todel[26];
    int depth;
    int size;
    int val;
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
            todel[i] = false;
        }
    }
};
vector<Node> tree_ptr;

int MergeTrees(Node* v1, Node* v2) {
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (v2->children[i] == nullptr) continue;
        if (v1->children[i] == nullptr) {
            res++;
            v1->children[i] = new Node();
            v1->todel[i] = true;
        }
        res += MergeTrees(v1->children[i], v2->children[i]);
    }
    return res;
}

void DemergeTrees(Node* v1, Node* v2) {
    for (int i = 0; i < 26; i++) {
        if (v2->children[i] == nullptr) continue;
        if (v1->children[i] != nullptr) {
            DemergeTrees(v1->children[i], v2->children[i]);
            if (v1->todel[i]) {
                delete v1->children[i];
                v1->children[i] = nullptr;
            }
        }
    }
}

void dfs(Node * v, int d) {
    v->depth = d;
    v->size = 1;
    int curr_max = 0;
    int child  = -1;
    for (int i = 0; i < 26; i++) {
        Node* a = v->children[i];
        if (a == nullptr) continue;
        dfs(a, d+1);
        v->size += a->size;
        if (a->size > curr_max) {
            curr_max = a->size;
            child = i;
        }
    }
    if (child == -1) v->val = 1;
    else {
        v->val = curr_max;
        for (int i = 0; i < 26; i++) {
            if (v->children[i] == nullptr) continue;
            if (i == child) continue;
            v->val += MergeTrees(v->children[child], v->children[i]);
        }
        for (int i = 0; i < 26; i++) {
            if (v->children[i] == nullptr) continue;
            if (i == child) continue;
            DemergeTrees(v->children[child], v->children[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    tree_ptr.resize(N+1);
    for (int i = 0; i < N-1; i++) {
        int f, a;
        char c;
        cin >> f >> a >> c;
        tree_ptr[f].children[c-'a'] = &tree_ptr[a];
    }
    dfs(&tree_ptr[1], 0);
    int total_size = tree_ptr[1].size;
    vector<int> depth_val(N, total_size);
    for (int i = 1; i <= N; i++) {
        depth_val[tree_ptr[i].depth] -=  (tree_ptr[i].size - tree_ptr[i].val);
    }
    int curr_min = 1e9;
    int curr_depth = 0;
    for (int i = 0; i < N; i++) {
        if (depth_val[i] < curr_min) {
            curr_depth = i;
            curr_min = depth_val[i];
        }
    }
    cout << curr_min << "\n" << (curr_depth+1);
}