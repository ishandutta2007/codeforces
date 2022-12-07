#include <bits/stdc++.h>
using namespace std;

int length(int x) {
    int ans = 0;
    while(x) {
        x /= 10;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        multiset <int> a, b;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.insert(x);
        }
        int ans = 0;
        while(!a.empty()) {
            int x = *(--a.end());
            int y = *(--b.end());
            if(x == y) {
                a.erase(a.find(x));
                b.erase(b.find(y));
                continue;
            }
            if(b.find(x) != b.end()) {
                a.erase(a.find(x));
                b.erase(b.find(x));
                continue;
            }
            if(a.find(y) != a.end()) {
                a.erase(a.find(y));
                b.erase(b.find(y));
                continue;
            }
            ans++;
            if(x > y) {
                a.erase(a.find(x));
                a.insert(length(x));
            } else {
                b.erase(b.find(y));
                b.insert(length(y));
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}