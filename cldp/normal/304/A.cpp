#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1100;


int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 5; i <= n; ++i) {
        for (int j = 3; j <= i; ++j) {
            int t = sqrt(i * i - j * j);
            if (t < j) break;
            if (t * t + j * j == i * i) ++ans;
        }
    }
    
    cout << ans << endl;
    return 0;
}