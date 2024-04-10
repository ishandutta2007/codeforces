#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    vector<vector<int>> G(26);
    for(int n = 0; n + 1 < N; ++n) {
        for(int i = 0; i < int(A[n].length()); ++i) {
            if(i >= int(A[n + 1].length())) {
                cout << "Impossible\n";
                return 0;
            }
            if(A[n][i] != A[n + 1][i]) {
                G[A[n + 1][i] - 'a'].push_back(A[n][i] - 'a');
                break;
            }
        }
    }
    string ans;
    vector<int> visited(26, 0);
    function<void(int)> topological_sort = [&](int n) {
        visited[n] = 1;
        for(int x : G[n]) {
            if(visited[x] == 1) {
                cout << "Impossible\n";
                exit(0);
            }
            if(visited[x] == 0) {
                topological_sort(x);
            }
        }
        ans.push_back('a' + n);
        visited[n] = 2;
    };
    for(int n = 0; n < 26; ++n) {
        if(visited[n] == 0) {
            topological_sort(n);
        }
    }
    cout << ans << '\n';
}