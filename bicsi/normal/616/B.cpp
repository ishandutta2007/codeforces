#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int main() {
    int n, m, a;
    cin>>n>>m;

    int sol = 0;

    for(int i=1; i<=n; i++) {
        int minn = 1e9 + 10;
        for(int j=1; j<=m; j++) {
            cin >> a;
            minn = min(minn, a);
        }
        sol = max(sol, minn);
    }

    cout << sol;

}