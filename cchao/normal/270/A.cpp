#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << ((360 % (180 - n))==0? "YES": "NO") << endl;
    }
    return 0;
}