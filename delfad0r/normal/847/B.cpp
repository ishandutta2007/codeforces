#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    vector<vector<int>> V;
    cin >> N;
    while(N--) {
        int x;
        cin >> x;
        int lo = 0, hi = V.size();
        while(lo < hi) {
            int m = (lo + hi) / 2;
            if(V[m].back() < x) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        if(lo == int(V.size())) {
            V.emplace_back(1, x);
        } else {
            V[lo].push_back(x);
        }
    }
    for(auto& v : V) {
        for(int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}