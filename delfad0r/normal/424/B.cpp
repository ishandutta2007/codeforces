#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<pair<double, int>> V(N);
    for(int n = 0; n < N; ++n) {
        int x, y;
        cin >> x >> y >> V[n].second;
        V[n].first = sqrt(x * x + y * y);
    }
    sort(V.begin(), V.end());
    for(auto& p : V) {
        S += p.second;
        if(S >= 1000000) {
            cout << fixed << setprecision(10) << p.first << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}