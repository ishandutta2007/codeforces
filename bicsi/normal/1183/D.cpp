#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        vector<pair<int, int>> v(n, make_pair(0, 0));
        for (int i = 0; i < n; ++i) {
            int tp, f; cin >> tp; f = 0;// >> f; 
            --tp;
            v[tp].first += 1;
            v[tp].second += f;
        }

        sort(v.rbegin(), v.rend());
        int maxx = 1e9;
        int fst = 0, snd = 0;
        for (int i = 0; i < n; ++i) {
            maxx = min(maxx - 1, v[i].first);
            if (maxx == 0) break;
            fst += maxx;
            snd += min(maxx, v[i].second);
        }
        cout << fst << '\n';
        // cout << fst << " " << snd << '\n';
    }

    return 0;
}