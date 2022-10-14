#include <iostream>
using namespace std;

int main() {
    int n; cin >> n; int p = 1; cout << p;
    int t = n, q = 1;
    for(int i=0; i<t-1; i++) {
        p = p + --n * q; q *= -1;
        cout << ' ' << p;
    }
    cout << endl;
}