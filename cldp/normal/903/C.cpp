#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int N, M = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x, x + N);
    for (int i = 0; i < N; ++i) {
        bool flag = false;
        for (int j = 0; j < M; ++j) {
            if (x[j] < x[i]) {
                x[j] = x[i];
                flag = true;
                break;
            }
        }
        if (!flag) {
            x[M] = x[i];
            ++M;
        }
    }
    cout << M << endl;
    
    return 0;
}