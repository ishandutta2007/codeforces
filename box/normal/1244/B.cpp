#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int first = -1, last = -1;
        for(int i=0; i<n; i++) {
            char c; cin >> c;
            if(c == '1') last = i;
            if(first == -1) first = last;
        }
        if(first == -1) cout << n << endl;
        else cout << max(n, max(2*n-2*first, 2*last+2)) << endl;
    }
}