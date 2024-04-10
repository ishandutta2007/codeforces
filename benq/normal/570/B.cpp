#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    if (2*m > (n+1)) {
        cout << m-1 << endl;
    } else if (2*m < (n+1)) {
        cout << m+1 << endl;
    } else {
        cout << m-1 << endl;
    }
    return 0;
}