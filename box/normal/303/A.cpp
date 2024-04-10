#include <iostream>
#include <algorithm>
using namespace std;

inline int aabs(int x) {
    if(x<0) return -x;
    return x;
}

int main() {
    int n; cin >> n;
    if(n == 1) {
        cout << "0\n0\n0" << endl;
        return 0;
    }
    for(int v=2; v<n; v++) {
        int w = (v+n-1)%n;
        if(__gcd(n, v) == 1 && __gcd(n, w) == 1) {
            for(int i=0; i<n; i++) {
                if(i != 0) cout << ' ';
                cout << (v*i) % n;
            }
            cout << endl;
            for(int i=0; i<n; i++) {
                if(i != 0) cout << ' ';
                cout << ((-w*i) % n + n) % n;
            }
            cout << endl;
            for(int i=0; i<n; i++) {
                if(i != 0) cout << ' ';
                cout << i;
            }
            cout << endl;
            return 0;
        }
    } 
    cout << -1 << endl;
}