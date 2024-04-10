#include <iostream>

using namespace std;

int T, S, q;

int restart(int downloaded) {
    return downloaded*q;
}

int main() {
    cin >> T >> S >> q;
    
    int a = 1;
    int b = S;
    while (restart(b) < T) {
        b = restart(b);
        a ++;
    }
    
    cout << a << endl;
}