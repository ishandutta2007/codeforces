//  228

#include <iostream>
using namespace std;
long long n, m, d, l;
int main() {
    cin >> n >> d >> m >> l;
    long long a = 0, b = 0;
    for (long long i = 1; i <= n; i++) {
        a = (i - 1) * m + l, b = i * m - 1;
        if (a / d != b / d) break;
    }
    cout << (a / d + 1) * d << endl;
    return 0;
}