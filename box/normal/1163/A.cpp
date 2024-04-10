#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if(m == 0) { cout << 1 << endl; return 0; }
    if(m == n) { cout << 0 << endl; return 0; }
    int rc = m, ans = 0;
    for(int cat=0; cat<n; cat++) {
        if(cat % 2) rc--;
        else {
            if(n-cat-1 >= rc) ans++;
            else rc--;
        }
        if(rc == 0) break;
    }
    cout << ans << endl;
}