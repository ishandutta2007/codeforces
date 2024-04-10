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
        deque <int> v(n);
        int z = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        while(!v.empty() && v.front() == 0) {
            z++;
            v.pop_front();
        }
        while((int)v.size() > 1) {
            deque <int> nv;
            for(int i = 1; i < (int)v.size(); i++) {
                nv.push_back(v[i] - v[i - 1]);
            }
            if(z > 0) {
                nv.push_back(v[0]);
                z--;
            }
            sort(nv.begin(), nv.end());
            while(!nv.empty() && nv.front() == 0) {
                z++;
                nv.pop_front();
            }
            v = nv;
        }
        cout << (v.empty() ? 0 : v.front()) << '\n';
    }
    
    return 0;
}