#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
long long x[1<<11];
long long y[1<<11];
long long X1, X2;

long long down(long long N, long long D) {
    if (D < 0) return down(-N, -D);
    if (N >= 0) return N / D;
    else return N / D - (N % D != 0);
}

long long up(long long N, long long D) {
    if (D < 0) return up(-N, -D);
    if (N >= 0) return N / D+ (N % D != 0);
    else return N / D;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int Y = y[0];
    for (int i = 0; i < n; i++) y[i] -= Y;
    if (x[0] > x[1]) {
        for (int i = 0; i < n; i++) y[i] = -y[i];
        reverse(x, x + n);
        reverse(y, y + n);
        for (int i = 0; i < n; i++) {
            x[i+n] = x[i];
            y[i+n] = y[i];
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = x[i+n-2];
            y[i] = y[i+n-2];
        }
    }
    
    X1 = x[0];
    X2 = x[1];
    
    for (int i = 2; i < n - 1; i++) {
        if (y[i] == y[i+1]) {
            if (x[i] < x[i+1]) {
                cout << 0 << endl; return;
            }
        } else {
            if (y[i] > y[i+1]) {
                X2 = min(X2, down(x[i] * (y[i+1]-y[i]) - y[i]*(x[i+1]-x[i]), y[i+1] - y[i]));
            } else {
                X1 = max(X1, up(x[i] * (y[i+1]-y[i]) - y[i]*(x[i+1]-x[i]), y[i+1] - y[i]));
            }
        }
    }
    
    cout << max(0LL, X2 - X1 + 1) << endl;
}

int main() {
    solve();
    return 0;
}