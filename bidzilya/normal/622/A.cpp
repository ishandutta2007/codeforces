#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (int len = 1; ; ++len) {
        if (n <= len) {
            cout << n << endl;
            return 0;
        } else {
            n -= len;
        }
    }
}