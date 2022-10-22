#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1100;


int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cout << i << " ";
    }
    cout << n-1 << endl;
    for (int i = 1; i < n; ++i) cout << i << " ";
    cout << 0 << endl;
    for (int i = 0; i < n - 1; ++i) cout << (i + i + 1) % n << " ";
    cout << (n + n - 1) % n << endl;
    return 0;
}