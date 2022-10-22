#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const long long INFF = 1LL * 100000000 * 10000000;
const int MAXN = 100010;

long long ans = 0;
long long X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> X[i];
    map<long long, long long> C;
    long long temp = 0;
    for (int i = 0; i < N; ++i) {
        temp += X[i];
        ++C[temp];
    }
    
    temp = 0;
    for (int i = 0; i < N; ++i) {
        ans += C[1 + temp];
        if (K == 1) {
            
        } else 
        if (K == -1) {
            ans += C[-1 + temp];
        } else {
            long long KK = K;
            while (abs(KK) <= INFF) {
                ans += C[KK + temp];
                KK *= K;
            }
        }
        temp += X[i];
        --C[temp];
    }
    cout << ans << endl;
    return 0;
}