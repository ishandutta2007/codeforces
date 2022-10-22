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
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        K += 5 * i;
        if (K <= 240) continue; 
        cout << i - 1 << endl;
        return 0;
    }
    cout << N << endl;
    return 0;
}