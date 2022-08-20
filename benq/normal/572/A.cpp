#include <iostream>

using namespace std;

int a,b,k,m, a1[100000], b1[100000];

int main() {
    cin >> a >> b >> k >> m;
    
    for (int i = 0; i < a; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >> b1[i];
    }
    
    if (a1[k-1] < b1[b-m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}