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
    int N;
    cin >> N;
    int x = 0, y = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > 0) ++x; else ++y;
    }
    if (x <= 1 || y <= 1) cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}