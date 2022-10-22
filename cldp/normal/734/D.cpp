#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 500010;

char C[MAXN];
int X[MAXN], Y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    long long x0, y0;
    cin >> N >> x0 >> y0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i] >> X[i] >> Y[i];
    }
    
    char CCL = 'B', CCR = 'B';
    long long L = -1000000001, R = 1000000001;
    for (int i = 0; i < N; ++i) {
        if (X[i] == x0) {
            if (Y[i] > y0 && Y[i] < R) {
                R = Y[i];
                CCR = C[i];
            }
            if (Y[i] < y0 && Y[i] > L) {
                L = Y[i];
                CCL = C[i];
            }
        }
    }
    if (CCL != 'B' || CCR != 'B') {
        cout << "YES" << endl;
        return 0;
    }
    
    CCL = 'B', CCR = 'B';
    L = -1000000001, R = 1000000001;
    for (int i = 0; i < N; ++i) {
        if (Y[i] == y0) {
            if (X[i] > x0 && X[i] < R) {
                R = X[i];
                CCR = C[i];
            }
            if (X[i] < x0 && X[i] > L) {
                L = X[i];
                CCL = C[i];
            }
        }
    }
    if (CCL != 'B' || CCR != 'B') {
        cout << "YES" << endl;
        return 0;
    }
    
    CCL = 'R', CCR = 'R';
    L = -1000000001, R = 1000000001;
    for (int i = 0; i < N; ++i) {
        if (X[i] + Y[i] == x0 + y0) {
            if (X[i] > x0 && X[i] < R) {
                R = X[i];
                CCR = C[i];
            }
            if (X[i] < x0 && X[i] > L) {
                L = X[i];
                CCL = C[i];
            }
        }
    }
    if (CCL != 'R' || CCR != 'R') {
        cout << "YES" << endl;
        return 0;
    }
    
    CCL = 'R', CCR = 'R';
    L = -1000000001, R = 1000000001;
    for (int i = 0; i < N; ++i) {
        if (X[i] - Y[i] == x0 - y0) {
            if (X[i] > x0 && X[i] < R) {
                R = X[i];
                CCR = C[i];
            }
            if (X[i] < x0 && X[i] > L) {
                L = X[i];
                CCL = C[i];
            }
        }
    }
    if (CCL != 'R' || CCR != 'R') {
        cout << "YES" << endl;
        return 0;
    }
    
    cout << "NO" << endl;
    
    return 0;
}