#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

typedef long long ll;

int memo[1<<10][1<<10];
int a[1<<10];
int n;

int f(int y, int x, bool out) {
    if (out) {
        int res = 0;
        if (y >= n) return res;
        if (x >= n) {
            cout << y + 1 << endl; 
            return res;
        }
        if (x == n - 1) {
            cout << y + 1 << ' ' << x + 1 << endl;
            return res;
        }
        if (memo[y][x] == max(a[y], a[x]) + f(x + 1, x + 2, false)) {
            cout << y + 1 << ' ' << x + 1 << endl;
            f(x + 1, x + 2, true);
            return res;
        }
        if (memo[y][x] == max(a[y], a[x+1]) + f(x, x + 2, false)) {
            cout << y + 1 << ' ' << x + 2 << endl;
            f(x, x + 2, true);
            return res;
        }
        if (memo[y][x] == max(a[x], a[x+1]) + f(y, x + 2, false)) {
            cout << x + 1 << ' ' << x + 2 << endl;
            f(y, x + 2, true);
            return res;
        }
    return res;
    }
    
    if (y >= n) return 0;
    if (x >= n) return a[y];
    
    if (memo[y][x] >= 0) return memo[y][x];
    if (x == n - 1) return max(a[y], a[x]);
    
    int& res = memo[y][x];
    res = 1<<30;
    res = min(max(a[y], a[x]) + f(x + 1, x + 2, out), res);
    res = min(max(a[y], a[x+1]) + f(x, x + 2, out), res);
    res = min(max(a[x], a[x+1]) + f(y, x + 2, out), res);
    
    return res;
}

int main() {
    cin >> n;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << f(0, 1, false) << endl;
    f(0, 1, true);
    return 0;
}