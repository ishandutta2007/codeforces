#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;



int main() {
    ios_base::sync_with_stdio(false);
    long long A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = 2; i <= 60; ++i) {
        long long C = (1LL << i) - 1;
        for (int j = 0; j < i - 1; ++j) {
            long long D = C - (1LL << j);
            if (A <= D && D <= B) {
                ++ans;
              //  cout << C << " " << D << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}