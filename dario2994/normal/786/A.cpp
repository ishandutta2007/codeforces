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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define endl "\n";

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = 8000; 


int res[2][MAXN];
int winning_val[2][MAXN];

int main() {
    ios::sync_with_stdio(false);
    int N;
    int K1, K2;
    cin >> N;
    cin >> K1;
    vector<int> S[2];
    S[0].resize(K1);
    for (int i = 0; i < K1; i++) cin >> S[0][i];
    cin >> K2;    
    S[1].resize(K2);
    for (int i = 0; i < K2; i++) cin >> S[1][i];

    res[0][0] = -1; // lose
    res[1][0] = -1;
    vector<pair<int, int>> todo; // player, position
    todo.push_back({0, 0});
    todo.push_back({1, 0});
    while (!todo.empty()) {
        int player = todo.back().first;
        int enemy = (player+1)%2;
        int pos = todo.back().second;
        todo.pop_back();
        if (res[player][pos] == -1) {
            for (int s : S[enemy]) {
                int prev = (N+pos - s) % N;
                if (res[enemy][prev]) continue;
                res[enemy][prev] = 1;
                todo.push_back({enemy, prev});
            }
        } else {
            for (int s : S[enemy]) {
                int prev = (N+pos - s) % N;
                if (res[enemy][prev]) continue;
                winning_val[enemy][prev]++;
                if (winning_val[enemy][prev] == (int)S[enemy].size()) {
                    res[enemy][prev] = -1;
                    todo.push_back({enemy, prev});
                }
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (res[0][i] == 1) cout << "Win";
        if (res[0][i] == 0) cout << "Loop";
        if (res[0][i] == -1) cout << "Lose";
        cout << " ";
    }
    cout << "\n";
    for (int i = 1; i < N; i++) {
        if (res[1][i] == 1) cout << "Win";
        if (res[1][i] == 0) cout << "Loop";
        if (res[1][i] == -1) cout << "Lose";
        cout << " ";
    }
}