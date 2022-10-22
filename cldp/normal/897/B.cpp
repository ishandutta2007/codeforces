#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
string Q;

int main() {
    ios_base::sync_with_stdio(false);
    int N, P;
    cin >> N >> P;
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        int M = i;
        vector<int> X;
        while (M > 0) {
            X.push_back(M % 10);
            M /= 10;
        }
        long long temp = 0;
        for (int i = X.size() - 1; i >= 0; --i) temp = (temp * 10 + X[i]) % P;
        for (int i = 0; i < X.size(); ++i) temp = (temp * 10 + X[i]) % P;
        ans = (ans + temp) % P;
    }
    cout << ans << endl;
    return 0;
}