#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    cin >> n;
    for (int i = 1; ; ++i) {
        if (i >= n) {
            cout << n << endl;
            return 0;
        }
        n -= i;
    }
    return 0;
}