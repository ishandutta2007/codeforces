#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    cout << m+n-1 << endl;
    for(int i = 1; i <= n; ++i)
        cout << 1 << ' ' << i << endl;
    for(int i = 2; i <= m; ++i)
        cout << i << ' ' << 1 << endl;
    return 0;
}