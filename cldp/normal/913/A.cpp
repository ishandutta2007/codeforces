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
    int N, M;
    cin >> M >> N;
    if (M >= 30) {
        cout << N << endl;
    } else {
        cout << N % (1 << M) << endl;
    }
    return 0;
}