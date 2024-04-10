#include <iostream>
using namespace std;

inline int daru(int a, int b) {
    return (a/b) + (int)((bool)(a%b));
}

int main() {
    int moves = 0, prev = 0;
    int n, d; cin >> n >> d;
    while(n --> 0) {
        int v; cin >> v;
        if(v <= prev) {
            int i = daru(prev - v, d);
            v += i*d;
            moves += i;
        }
        if(v == prev) {
            v += d;
            moves++;
        }
        prev = v;
    }
    cout << moves << endl;
}