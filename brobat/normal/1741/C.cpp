#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        vector<vector<int>> z;
        for(int i = 0; i < n; i++) {
            // let current thickness be v[0...i].
            vector <int> temp;
            int x = 0;
            for(int j = 0; j <= i; j++) x += v[j];
            temp.push_back(i);
            if(sum % x != 0) continue;
            int j = i + 1;
            int curr = 0;
            bool pos = true;
            while(j < n) {
                curr += v[j];
                if(curr > x) {
                    pos = false;
                    break;
                } else if(curr == x) {
                    temp.push_back(j);
                    curr = 0;
                    j++;
                } else {
                    j++;
                }
            }
            if(temp.back() != n - 1) {
                if(curr != x) pos = false;
                else temp.push_back(n - 1);
            }
            if(pos) z.push_back(temp);
        }
        int ans = n;
        for(auto i : z) {
            int mx = i.front() + 1;
            for(int j = 1; j < (int)i.size(); j++) {
                mx = max(mx, i[j] - i[j - 1]);
            }
            ans = min(ans, mx);
        }
        cout << ans << '\n';
    }
    
    return 0;
}