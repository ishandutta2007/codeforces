#include <iostream>

using namespace std;

int main() {

    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = a + b + c;
    ans = min(ans, 2 * (a + c));
    ans = min(ans, 2 * (b + c));
    ans = min(ans, 2 * (a + b));
    cout << ans;

    return 14 / 88;

}