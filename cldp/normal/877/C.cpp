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
    if (N & 1) {
        cout << N / 2 + N << endl;
        for (int i = 2; i <= N; i += 2) cout << i << " ";
        for (int i = 1; i <= N; i += 2) cout << i << " ";
        for (int i = 2; i <= N; i += 2) cout << i << " ";
        cout << endl;
    } else {
        cout << 3 * N / 2 << endl;
        for (int i = 1; i <= N; i += 2) cout << i << " ";
        for (int i = 2; i <= N; i += 2) cout << i << " ";
        for (int i = 1; i <= N; i += 2) cout << i << " ";
        cout << endl;
    }
    return 0;
}