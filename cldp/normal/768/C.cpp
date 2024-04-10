#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1030;

int X[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K, P;
    cin >> N >> K >> P;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ++X[0][a];
    }
    int cur = 0;
    while (K--) {
        cur = 1 - cur;
        for (int i = 0; i < MAXN; ++i) X[cur][i] = 0;
        bool flag = false;
        for (int i = 0; i < MAXN; ++i) {
            if (X[!cur][i] == 0) continue;
            X[cur][i] += X[!cur][i] / 2;
            X[cur][i ^ P] += X[!cur][i] / 2;
            if (X[!cur][i] % 2 == 0) continue;
            
            if (!flag) {
                X[cur][i ^ P] += 1;
            } else {
                X[cur][i] += 1;
            }
            flag = !flag;
        }
    }
    
    int A = 0, B = MAXN;
    for (int i = 0; i < MAXN; ++i) {
        if (X[cur][i] > 0) {
            A = max(A, i);
            B = min(B, i);
        }
    }
    cout << A << " " << B << endl;
    
    
    return 0;
}