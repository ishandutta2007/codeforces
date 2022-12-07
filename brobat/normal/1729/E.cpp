#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int z; cin >> z;
    return z;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q = 0;
    int n = -1;
    for(int j = 2; j <= 20; j++) {
        for(int i = 1; i < j; i++) {
            if(n >= 0) break;
            assert(q <= 50);
            int x = ask(i, j);
            int y = ask(j, i);
            q += 2;
            if(x == -1) {
                n = j - 1;
                break;
            } else if(x != y) {
                n = x + y;
                break;
            }
        }
    }
    assert(n != -1);
    cout << "! " << n << endl;
    
    return 0;
}