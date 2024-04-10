#include <bits/stdc++.h>

using namespace std;

int N;
int L[200];
int R[200];
bool visited[200];

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        cin >> L[n] >> R[n];
        --L[n];
        --R[n];
    }
    vector<pair<int, int>> lists;
    for(int n = 0; n < N; ++n) {
        if(visited[n]) {
            continue;
        }
        visited[n] = true;
        int m = n;
        while(L[m] >= 0) {
            m = L[m];
            visited[m] = true;
        }
        int k = n;
        while(R[k] >= 0) {
            k = R[k];
            visited[k] = true;
        }
        lists.emplace_back(m, k);
    }
    for(unsigned i = 0; i < lists.size(); ++i) {
        if(i > 0) {
            L[lists[i].first] = lists[i - 1].second;
        }
        if(i + 1 < lists.size()) {
            R[lists[i].second] = lists[i + 1].first;
        }
    }
    for(int n = 0; n < N; ++n) {
        cout << L[n] + 1 << ' ' << R[n] + 1 << '\n';
    }

}