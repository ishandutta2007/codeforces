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
    int K, N;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> N;
        bool flag = false;
        for (int a = 0; a < 35; ++a) {
            for (int b = 0; b < 20; ++b) {
                if (a * 3 + b * 7 == N) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}