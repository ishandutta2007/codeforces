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
    int a, b, c;
    cin >> a >> b >> c;
    a = a % b;
    for (int i = 0; i < 10000000; ++i) {
        int t = a * 10 / b;
        if (t == c) {
            cout << i + 1 << endl;
            return 0;
        }
        a = a * 10 % b;
    }
    cout << -1 << endl;
    return 0;
}