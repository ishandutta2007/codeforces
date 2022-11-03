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

int main() {
    int N;
    cin >> N;
    string to_guess;
    cin >> to_guess;
    vector<bool> present1(26, false);
    for (char c : to_guess) {
        if (c == '*') continue;
        present1[c-'a'] = true;
    }
    int K;
    cin >> K;
    vector<bool> all_present(26, true);
    for (int k = 0; k < K; k++) {
        string s;
        cin >> s;
        bool compatible = true;
        for (int i = 0; i < N; i++) {
            if (to_guess[i] != '*' and to_guess[i] != s[i]) compatible = false;
            if (to_guess[i] == '*' and present1[s[i]-'a']) compatible = false;
        }
        if (!compatible) continue;
        vector<int> present(26, false);
        for (char c : s) present[c-'a'] = true;
        for (int i = 0; i < 26; i++) all_present[i] = (all_present[i] && present[i]);
    }
    int res = 0;
    for (int i = 0; i < 26; i++) res += (all_present[i] and !present1[i]);
    cout << res << "\n";
}