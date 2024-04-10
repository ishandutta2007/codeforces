#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int a=0, b=0, c=0;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a ^= t;
    }
    for(int i = 1; i < n; ++i) {
        int t;
        cin >> t;
        b ^= t;
    }
    for(int i = 2; i < n; ++i) {
        int t;
        cin >> t;
        c ^= t;
    }
    
    cout << (b ^ a) << "\n";
    cout << (c ^ b) << "\n";
    
    return 0;
}