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

// This should not compile if used.
const int MAXN = -1;

// #include "../../CompetitiveProgrammingAlgos/read_graph.cpp"

char G[13][2];


bool ok(int a, int b) {
    if (0 <= a and a < 13 and 0 <= b and b < 2) {
        return G[a][b] == 0;
    }
    return false;
}

void WriteString(string s, int x, int y, int dx, int dy) {
    if (s.empty()) return;
    G[x][y] = s[0];
    s.erase(0, 1);
    for (int m1 = 0; m1 < 4; m1++) {
        if (ok(x+dx, y+dy)) {
            WriteString(s, x+dx, y+dy, dx, dy);
            return;
        }
        if (dx) {
            dy = dx;
            dx = 0;
        } else {
            dx = -dy;
            dy = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    for (int i = 0; i < 26; i++) {
        if (S[i] == S[i+1]) {
            cout << "Impossible";
            return 0;
        }
    }
    int first, second;
    for (int i = 0; i < 27; i++) {
        for (int j = i+1; j < 27; j++)
        if (S[i] == S[j]) {
            first = i;
            second = j;
        }
    }
    int q = second-first+1;
    int pos = (q)/2 -1; // mah
    WriteString(S.substr(first, q-1), pos, 1, -1, 0);
    string tmp_string = S.substr(0, first+1);
    reverse(tmp_string.begin(), tmp_string.end());
    WriteString(tmp_string, pos, 1, 1, 0);
    if (G[pos][0]) WriteString(S.substr(second+1), pos+1, 0, 1, 0);
    else WriteString(S.substr(second+1), pos, 0, 1, 0);
    for (int i = 0; i < 13; i++) cout << G[i][0];
    cout << "\n";
    for (int i = 0; i < 13; i++) cout << G[i][1];
}