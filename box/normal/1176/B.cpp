#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        vector<int> el;
        for(int i=0; i<3; i++) el.push_back(0);
        int n; cin >> n;
        while(n--) {
            int v; cin >> v;
            el[v%3]++;
        }
        int paired = min(el[1], el[2]);
        el[1] -= paired;
        el[2] -= paired;
        paired += el[0];
        paired += el[1]/3;
        paired += el[2]/3;
        cout << paired << endl;
    }
}