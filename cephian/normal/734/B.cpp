#include <iostream>

using namespace std;

int main() {
    int a2,a3,a5,a6;
    cin >> a2 >> a3 >> a5 >> a6;
    int ans = 0;
    int m = min(a2,min(a5,a6));
    ans += 256*m;
    a2 -= m;
    ans += min(a3,a2)*32;
    cout << ans << "\n";
    return 0;
}