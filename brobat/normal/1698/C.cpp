#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] > 0) cnt1++;
            if(v[i] < 0) cnt3++;
            if(v[i] == 0) cnt2++;
        }
        vector <int> w;
        if(cnt1 > 3 || cnt3 > 3) {
            cout << "NO\n";
            continue;
        }
        if(cnt2 > 0) w.push_back(0);
        for(int i = 0; i < n; i++) {
            if(v[i] != 0) w.push_back(v[i]);
        }
        sort(w.begin(), w.end());
        map <int, int> m;
        for(auto i : w) m[i] = true;
        int x = w.size();
        bool pos = true;
        for(int i = 0; i < x; i++) {
            for(int j = i + 1; j < x; j++) {
                for(int k = j + 1; k < x; k++) {
                    int y = w[i] + w[j] + w[k];
                    pos &= m[y];
                }
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}