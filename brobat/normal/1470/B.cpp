#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000100;
int sq[N + 1];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    for(int i = 0; i <= N; i++) {
        sq[i] = i;
    }
    for(int i = 1; i <= N; i++) {
        if(sq[i] == i) {
            for(int j = 2; j <= 1000; j++) {
                if(i * (j * j) >= N) break;
                sq[i * (j * j)] = i;
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] = sq[v[i]];
            cnt[v[i]]++;
        }
        int ans1 = 0;
        int ans2 = 0;
        for(auto i : cnt) {
            ans1 = max(ans1, i.second);
        }
        map<int, int> cnt2;
        for(auto i : cnt) {
            if(i.second % 2 == 1) {
                cnt2[i.first] += i.second;
            } else {
                cnt2[1] += i.second;
            }
        }
        for(auto i : cnt2) {
            ans2 = max(ans2, i.second);
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if(x == 0) cout << ans1 << '\n';
            else cout << ans2 << '\n';
        }
    }
    
    return 0;
}