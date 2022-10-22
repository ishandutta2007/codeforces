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
    string Q;
    cin >> N >> Q;
    int ans = 0, x = 0, y = 0;
    int p = -1;
    for (int i = 0; i < N; ++i) {
        if (Q[i] == 'U') ++y; else ++x;
        int q = p;
        if (x > y) q = 1; 
        if (x < y) q = 0;
        if (p != -1) {
            if (p != q) ++ans;
        }
        p = q;
    }
    cout << ans << endl;
    return 0;
}