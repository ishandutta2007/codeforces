#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;


int main() {
    long long p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    long long a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (p / a < q) 
            p = -1;
        else
            p -= q * a;
        if (p < 0) {
            cout << "NO" << endl;
            return 0;
        }
        swap(p, q);
    }
    
    if (q == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    

    return 0;
}