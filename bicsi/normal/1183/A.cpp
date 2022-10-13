#include <bits/stdc++.h>

using namespace std;

bool Interesting(int x) {
    int ans = 0;
    while (x) {
        int dig = x % 10;
        x /= 10;
        ans += dig;
    }
    return ans % 4 == 0;
}

int main() {
    int x; cin >> x;
    while (!Interesting(x)) ++x;
    cout << x << endl;
    return 0;
}