#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int main() {
    int a, c;
    cin >> a >> c;

    int ans = 0;
    int pw = 1;
    while (a > 0 || c > 0) {
        ans += pw * ( ( (c % 3) + 6 - (a % 3) ) % 3 );
        a /= 3;
        c /= 3;
        pw *= 3;
    }
    cout << ans << endl;
}