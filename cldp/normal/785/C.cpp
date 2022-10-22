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
const int MAXN = 2010;



int main() {
    ios_base::sync_with_stdio(false);
    long long N, M;
    cin >> N >> M;
    if (N <= M) {
        cout << N << endl;
        return 0;    
    }
    
    long long L = M, R = 1LL * 1000000000 * 1000000000;
    while (L + 1 < R) {
        long long mid = (L + R) / 2;
        double mm = mid;
        long long P = mid - M;
        double PP = mid - M;
        if (PP * (PP - 1) / 2 + mm >= N + N) {
            R = mid;
            continue;
        }
        
        if (P * (P - 1) / 2 + mid >= N) {
            R = mid; 
        } else {
            L = mid;
        }
    }
    
    cout << R << endl;
    
    return 0;
}