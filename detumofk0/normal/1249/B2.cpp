#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int nTest; cin >> nTest;
    while(nTest--) {
        int n; cin >> n;
        vector < int > a(n), lab(n, -1);
        for(int &x : a) cin >> x, --x;

        function < int(int) > find = [&](int x) {
            return lab[x] < 0 ? x : lab[x] = find(lab[x]);
        };

        for(int i = 0; i < n; ++i) {
            int x = find(i);
            int y = find(a[i]);
            if(x == y) continue;
            lab[x] += lab[y];
            lab[y] = x;
        }

        for(int i = 0; i < n; ++i) {
            int x = find(i);
            cout << -lab[x] << " ";
        }

        cout << endl;
    }

    return 0;
}