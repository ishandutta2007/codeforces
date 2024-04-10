#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;

int Y[MAXN];
int X[MAXN];
int ans[MAXN];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) ans[i] = INF;

    for (int i = 0; i < 10; ++i) {
        int d = (1 << i);
        int s = 0, cnt = 0;
        for (int j = 0; j < N; j += d) {
            for (int k = j; k < min(j + d, N); ++k) {
                Y[k] = s;
                if (s == 1) ++cnt;
            }
            s = 1 - s;
        }
        if (cnt == 0) break;
        cout << cnt << endl << flush;
        for (int j = 0; j < N; ++j) {
            if (Y[j] == 1) cout << j + 1 << " ";
        }
        cout << endl << flush;
        for (int j = 1; j <= N; ++j) cin >> X[j];
        for (int j = 0; j < N; ++j) {
            if (Y[j] == 1) continue;
            ans[j + 1] = min(ans[j + 1], X[j + 1]);
        }
    }


    for (int i = 0; i < 10; ++i) {
        int d = (1 << i);
        int s = 1, cnt = 0;
        for (int j = 0; j < N; j += d) {
            for (int k = j; k < min(j + d, N); ++k) {
                Y[k] = s;
                if (s == 1) ++cnt;
            }
            s = 1 - s;
        }
        if (cnt == N) break;
        cout << cnt << endl << flush;
        for (int j = 0; j < N; ++j) {
            if (Y[j] == 1) cout << j + 1 << " ";
        }
        cout << endl << flush;
        for (int j = 1; j <= N; ++j) cin >> X[j];
        for (int j = 0; j < N; ++j) {
            if (Y[j] == 1) continue;
            ans[j + 1] = min(ans[j + 1], X[j + 1]);
        }
    }

    cout << -1 << endl << flush;
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}