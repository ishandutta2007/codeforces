#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

string Normalize(string name) {
    string res = "";
    for (int i = 0; i < (int)name.size(); i++) {
        if (name[i] == 'u') res += "oo";
        else if (name[i] == 'k' and i+1 < (int)name.size() and name[i+1] == 'h') {
            continue;
        } else res += name[i];
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    set<string> differents;
    for (int ii = 0; ii < N; ii++) {
        string name;
        cin >> name;
        for (int i = 0; i < 25; i++) name = Normalize(name);
        differents.insert(name);
    }
    cout << differents.size() << "\n";
}