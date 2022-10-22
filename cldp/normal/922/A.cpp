#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    if (y == 0) {
        cout << "No" << endl;
        return 0;
    }
    if (y == 1) {
        if (x > 0) cout << "No" << endl; else cout << "Yes" << endl;
        return 0;
    }
    if (y - 1 > x) {
        cout << "No" << endl;
        return 0;
    }
    int a = x - (y - 1);
    if (a & 1) cout << "No" << endl; else cout << "Yes" << endl;
    return 0;
}