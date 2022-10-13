#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    c -= 2; b -= 1;
    a = min(a, b);
    a = min(a, c);
    cout << a + a + 1 + a + 2 << endl;
    return 0;
}