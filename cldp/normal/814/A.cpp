#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> x[i];
    for (int j = 0; j < M; ++j) cin >> y[j];
    sort(y, y + M);
    bool flag = true;
    int k = M - 1;
    for (int i = 0; i < N; ++i) {
        if (x[i] != 0) continue;
        x[i] = y[k];
        --k;
    }
    for (int i = 1; i < N; ++i) {
        if (x[i - 1] >= x[i]) flag = false;
    }
    if (!flag) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}