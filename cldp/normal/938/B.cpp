#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool z[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        z[a] = true;
    }
    for (int i = 500000; i >= 1; --i) {
        if (z[i] || z[1000001 - i]) {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}