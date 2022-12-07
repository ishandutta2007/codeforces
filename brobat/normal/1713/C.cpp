#include <bits/stdc++.h>
using namespace std;

void check(vector <int> &v) {
    int n = v.size();
    map<int, int> m;
    for(auto i : v) m[i]++;
    for(auto i : m) {
        assert(i.second == 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mx = ceil(sqrt(n - 1)) * ceil(sqrt(n - 1));
        vector <int> ans(n);
        set <int> done;
        for(int i = n - 1; i >= 0; i--) {
            if(mx - i >= n || done.find(mx - i) != done.end()) {
                mx = ceil(sqrt(i)) * ceil(sqrt(i));
            }
            ans[i] = mx - i;
            done.insert(mx - i);
        }
        check(ans);
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}