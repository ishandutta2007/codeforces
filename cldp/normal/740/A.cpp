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
const int MAXN = 1010;


int main() {
    ios_base::sync_with_stdio(false);
    long long N, A, B, C;
    cin >> N >> A >> B >> C;
    if (N % 4 == 0) {
        cout << 0 << endl;
    } else
    if (N % 4 == 1) {
        cout << min(min(C, A + B), A * 3) << endl;
    } else 
    if (N % 4 == 2) {
        cout << min(min(B, C + C), A + A) << endl;
    } else {
        cout << min(min(A, B + C), C * 3) << endl;
    }
    
    return 0;
}