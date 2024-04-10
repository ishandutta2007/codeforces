#include <iostream>

using namespace std;

int main(void) {
    int l, p, q;
    cin >> l >> p >> q;
    cout << (float) p * l / (p + q);
    return 0;
}