#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool decreasing = false;
    int prev = -1;
    bool fahked = false;
    for(int i=0; i<n; i++) {
        int e; cin >> e;
        if(prev > e) decreasing = true;
        if(decreasing && prev < e) {
            fahked = true;
            break;
        }
        prev = e;
    }
    if(fahked) cout << "NO" << endl;
    else cout << "YES" << endl;
}