#include <iostream>
using namespace std;

int main() {
    int a = -1, b = -1;
    int n; cin >> n;
    while(n--) {
        int v; cin >> v;
        a = max(a, v);
    }
    cin >> n;
    while(n--) {
        int v; cin >> v;
        b = max(b, v);
    }
    cout << a << ' ' << b << endl;
}