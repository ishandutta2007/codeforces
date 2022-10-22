#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;

int x[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int N, M, C, a;
    cin >> N >> M >> C;
    for (int i = 1; i <= N; ++i) x[i] = -1;

    while (M--) {
        cin >> a;
        if (a <= (C + 1) / 2) {
            for (int i = 1; i <= N; ++i) {
                if (x[i] == -1) {
                    x[i] = a;
                    cout << i << endl << flush;
                    break;
                } else {
                    if (x[i] <= a) continue;
                    x[i] = a;
                    cout << i << endl << flush;
                    break;
                }
            }
        } else {
            for (int i = N; i >= 1; --i) {
                if (x[i] == -1) {
                    x[i] = a;
                    cout << i << endl << flush;
                    break;
                } else {
                    if (x[i] >= a) continue;
                    x[i] = a;
                    cout << i << endl << flush;
                    break;
                }
            }
        }

        bool flag = true;
        for (int i = 1; i <= N; ++i) {
            if (x[i] == -1) flag = false;
        }
        if (flag) break;
    }

    return 0;
}