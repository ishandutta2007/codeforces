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
    long long N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << N << endl; 
    } else {
        for (int i = 0; i < 70; ++i) {
            if ((1LL << i) - 1 < N) continue;
            cout << (1LL << i) - 1 << endl;
            break;
        }
    }
    return 0;
}