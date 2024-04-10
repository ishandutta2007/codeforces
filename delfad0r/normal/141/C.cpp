#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> SI;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<SI> V(N);
    for(SI& p : V) {
        cin >> p.first >> p.second;
    }
    sort(V.begin(), V.end(), [](SI& x, SI& y) { return x.second < y.second; });
    vector<SI> ans;
    for(int n = 0; n < N; ++n) {
        if(V[n].second > n) {
            cout << "-1\n";
            return 0;
        }
        ans.emplace(ans.begin() + V[n].second, V[n].first, N + 1 - n);
    }
    for(SI& p : ans) {
        cout << p.first << " "  << p.second << "\n";
    }
    
    return 0;
}