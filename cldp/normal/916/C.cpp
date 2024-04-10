#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const int PP = 1000033;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    cout << PP << " " << PP << endl;
    for (int i = 1; i < N - 1; ++i) {
        cout << i << " " << i + 1 << " " << 1 << endl;
    }
    cout << N - 1 << " " << N << " " << PP - (N - 2) << endl;
    int cnt = M - (N - 1);
    for (int i = 1; i < N; ++i) {
        if (cnt == 0) break;
        for (int j = i + 2; j <= N; ++j) {
            if (cnt == 0) break;
            cout << i << " " << j << " " << PP << endl;
            --cnt;
        }
    }
    return 0;
}