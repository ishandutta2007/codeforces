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
    long long A, B, x, y, z;
    cin >> A >> B >> x >> y >> z;
    cout << max(x + x + y - A, 0LL) + max(y + z + z + z - B, 0LL) << endl;
    return 0;
}