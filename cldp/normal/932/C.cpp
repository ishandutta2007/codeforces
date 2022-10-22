#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

void outt(int start, int times, int L) {
    while (times > 0) {
        for (int i = start + 1; i < start + L; ++i) cout << i << " ";
        cout << start << " ";
        start += L;
        --times;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, A, B;
    cin >> N >> A >> B;
    bool flag = false;
    for (int i = 0; i <= N / A; ++i) {
        if ((N - i * A) % B == 0) {
            flag = true;
            outt(1, i, A);
            outt(1 + i * A, (N - i * A) / B, B);
            return 0;
        }
    }
    if (!flag) {
        cout << -1 << endl;
    }
    return 0;
}