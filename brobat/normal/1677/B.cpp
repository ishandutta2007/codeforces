#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        deque <int> cols(m, 0);
        vector <int> ax(n*m, 0);
        int cnt = 0;
        for(int i = 0; i < n*m; i++) {
            int last = cols[m - 1];
            cols.pop_back();
            if(s[i] == '1' && last == 0) {
                cnt++;
            }
            cols.push_front((s[i] == '1' || last == 1) ? 1 : 0);
            ax[i] = cnt;
        }
        vector <int> o(n*m, 0);
        o[0] = (s[0] == '1' ? 1 : 0);
        for(int i = 1; i < n*m; i++) {
            o[i] = o[i - 1];
            if(s[i] == '1') o[i]++;
        }
        vector <int> ay(n*m, 0);
        for(int i = 0; i < m; i++) {
            if(o[i] > 0) {
                ay[i] = 1;
            }
        }
        for(int i = m; i < n*m; i++) {
            ay[i] = ay[i - m];
            if(o[i] - o[i - m] > 0) {
                ay[i]++;
            }
        }
        for(int i = 0; i < n*m; i++) {
            cout << ax[i] + ay[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}