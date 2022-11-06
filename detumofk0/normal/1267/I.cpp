#include<bits/stdc++.h>

using namespace std;

bool ask_greater(int x, int y) {
    cout << "? " << x << " " << y << endl;
    char c; cin >> c;
    return (c == '>');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector < pair < int, int > > a(n);
        for(int i = 0; i < n; ++i) {
            int u = i * 2 + 1;
            int v = i * 2 + 2;
            if(ask_greater(u, v)) a[i] = make_pair(u, v);
            else a[i] = make_pair(v, u);
        }

        sort(a.begin(), a.end(), [&](pair < int, int > x, pair < int, int > y){
            return ask_greater(x.second, y.second);
        });

        vector < int > perm;
        for(int i = 1; i < a.size(); ++i) {
            perm.push_back(a[i].first);
            perm.push_back(a[i].second);
        }

        sort(perm.begin(), perm.end(), [&](int x, int y){
            return ask_greater(x, y);
        });
        ask_greater(a.front().second, perm[n - 2]);
        cout << "!" << endl;
    }

    return 0;
}