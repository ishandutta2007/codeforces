#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int nTest; cin >> nTest;
    while(nTest--) {
        int n; cin >> n;
        int flag = 0;
        map < int, int > foo;

        while(n--) {
            int x; cin >> x;
            foo[x] = 1;
            flag |= foo[x - 1] | foo[x + 1];
        }

        cout << (1 + flag) << "\n";
    }

    return 0;
}