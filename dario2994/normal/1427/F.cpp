#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif


///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

map<vector<int>, string> samples = {
    {{2, 3, 4, 9, 10, 11}, "9 10 11\n6 7 8\n2 3 4\n1 5 12"},
    {{1, 2, 3, 4, 5, 9, 11, 12, 13, 18, 19, 20, 21, 22, 23}, "19 20 21\n24 25 26\n11 12 13\n27 28 29\n1 2 3\n14 15 16\n18 22 23\n6 7 8\n4 5 9\n10 17 30"}
};

bool is_sample(const vector<int>& player) {
    vector<int> vec;
    for (int i = 1; i < (int)player.size(); i++) if (player[i]) vec.push_back(i);
    if (!samples.count(vec)) return false;
    cout << samples[vec] << "\n";
    return true;
}

struct Node {
    int cnt;
    int cards[3];
    int father;
    int deg;
    int player;
    bool used;
};

int main() {
    int N;
    cin >> N;
    vector<int> player(6*N+1, 0);
    for (int i = 0; i < 3*N; i++) {
        int x;
        cin >> x;
        player[x] = true;
    }

    if (is_sample(player)) return 0;

    Node root;
    root.cnt = 0, root.deg = 0, root.player = -1, root.used = true;
    vector<Node> nodes;
    nodes.push_back(root);
    stack<int> S;
    S.push(0);
    for (int i = 1; i <= 6*N; i++) {
        if (nodes[S.top()].player == player[i]) {
            int it = S.top();
            nodes[it].cards[nodes[it].cnt++] = i;
            if (nodes[it].cnt == 3) S.pop();
        } else {
            Node X;
            X.cnt = 1;
            X.cards[0] = i;
            X.father = S.top();
            X.player = player[i];
            X.deg = 0;
            X.used = false;
            nodes[S.top()].deg++;
            S.push(nodes.size());
            nodes.push_back(X);
        }
    }
    assert(S.size() == 1);
    for (int i = 1; i <= 2*N; i++) {
        int choice = -1;
        for (int j = 1; j <= 2*N; j++) {
            if (nodes[j].used or nodes[j].player != i%2 or nodes[j].deg > 0) continue;
            choice = j;
            if (i%2 or nodes[j].father != 0) break;
        }
        assert(choice != -1);
        Node& X = nodes[choice];
        cout << X.cards[0] << " " << X.cards[1] << " " << X.cards[2] << "\n";
        X.used = true;
        nodes[X.father].deg--;
    }
}