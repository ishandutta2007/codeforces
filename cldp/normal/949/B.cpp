#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long find_0(long long A, long long B, long long C);

long long find_1(long long A, long long B, long long C) {
    if (B & 1) return A + (B + 1) / 2;
    if (C & 1) return find_0(A + (C + 1) / 2, C - (C + 1) / 2 - (C - B) / 2, C - (C + 1) / 2);
    if (B == C) return find_0(A + (C + 1) / 2, 1, C - (C + 1) / 2);
    return find_0(A + (C + 1) / 2, C - (C + 1) / 2 - (C - 1 - B) / 2, C - (C + 1) / 2);
}

// start with A + 1, with empty first, the Bth one, total C
long long find_0(long long A, long long B, long long C) {
 //   cout << A << " " << B << " " << C <<endl;
    if (C == 1) return A + 1;
    if (B % 2 == 0) return A + B / 2;
    if (C & 1) {
        return find_1(A + C / 2, C - C / 2 - (C - B) / 2, C - C / 2);
    }
    return find_0(A + C / 2, C - C / 2 - (C - B) / 2, C - C / 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    long long N;
    int Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; ++i) {
        long long a;
        cin >> a;
        cout << find_1(0, a, N) << endl;
    }
    return 0;
}