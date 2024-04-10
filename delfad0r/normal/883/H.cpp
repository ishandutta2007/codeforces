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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> occs(256, 0);
    for (char c : s) {
        occs[c]++;
    }
    vector<int> singles;
    for (int i = 0; i < 256; i++) {
        if (occs[i]%2) {
            occs[i]--;
            singles.push_back(i);
        }
        occs[i] /= 2;
    }
    string doub = "";
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < occs[i]; j++) doub += ('\0'+i);
    }
    if (singles.empty()) {
        cout << 1 << "\n";
        cout << doub;
        reverse(doub.begin(), doub.end());
        cout << doub;
        return 0;
    }
    int K = singles.size();
    int L = N;
    for (; L >= 1; L--) {
        if (N % L == 0 and L % 2 and N/L >= K) break;
    }
    while ((int)singles.size() < N/L) {
        singles.push_back(doub.back());
        singles.push_back(doub.back());
        doub.pop_back();
    }
    K = N/L;
    cout << K << "\n";
    
    for (int i = 0; i < N/L; i++) {
        string half = doub.substr(i*((L-1)/2), (L-1)/2);
        cout << half;
        cout << char('\0' + singles.back());
        reverse(half.begin(), half.end());
        cout << half;
        singles.pop_back();
        cout << "\n";
    }
}