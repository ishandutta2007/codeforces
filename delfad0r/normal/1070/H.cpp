#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    unordered_map<string, unordered_set<string>> M;
    for(int n = 0; n < N; ++n) {
        string S;
        cin >> S;
        for(int i = 0; i < int(S.length()); ++i) {
            for(int l = 1; i + l <= int(S.length()); ++l) {
                M[S.substr(i, l)].insert(S);
            }
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        string S;
        cin >> S;
        if(M.count(S)) {
            cout << M[S].size() << ' ' << *M[S].begin() << '\n';
        } else {
            cout << "0 -\n";
        }
    }
}