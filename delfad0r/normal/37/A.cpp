#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for(int n = 0; n < N; ++n) {
        cin >> V[n];
    }
    sort(V.begin(), V.end());
    int H = 1, T = 1, h = 1;
    for(int n = 1; n < N; ++n) {
        if(V[n] == V[n - 1]) {
            ++h;
        } else {
            ++T;
            h = 1;
        }
        H = max(H, h);
    }
    cout << H << ' ' << T << '\n';
}