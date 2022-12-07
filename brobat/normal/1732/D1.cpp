#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int q;
    cin >> q;
    set <int> s;
    map <int, int> mex;
    while(q--) {
        char c; int x;
        cin >> c >> x;
        if(c == '+') {
            s.insert(x);
        } else {
            int curr = x;
            if(mex.find(x) != mex.end()) {
                curr = mex[x];
            }
            while(s.find(curr) != s.end()) {
                curr += x;
            }
            mex[x] = curr;
            cout << mex[x] << '\n';
        }
    }
    
    return 0;
}