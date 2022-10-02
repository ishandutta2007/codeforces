#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif


unordered_map<string, int> ss;
unordered_map<string, string> bb;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string f;
        cin >> f;
        set<string> sub;
        for (int a = 0; a < (int)f.size(); a++) {
            for (int b = 1; a+b <= (int)f.size(); b++) sub.insert(f.substr(a, b));  
        }
        for (string s : sub) ss[s]++, bb[s] = f;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        cout << ss[s] << " ";
        if (ss[s] > 0) cout << bb[s] << "\n";
        else cout << "-\n";
    }
}