#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 1001;

ld D[10*N + 10][N];

const ld eps = (1e-7)*(1.0/2000.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    D[1][1] = 1;
    for (int i = 0; i < N; ++i) D[i][0] = 0;
    
    int k, q;
    cin >> k >> q;
    
    for (int i = 2; i <= 10*N; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            D[i][j] = D[i - 1][j]*ld(j)/ld(k)  + D[i - 1][j - 1]*ld(k - j + 1)/ld(k);
        }
    }
    
    while (q--) {
        ld kt;
        cin >> kt;
        kt /= 2000.0;
        int a =  k - 1;
        int b = 10*N;
        while (a  + 1 < b) {
            int c = (a + b)/2;
            if (D[c][k] > kt - eps) b = c;
            else a = c;
        }
        cout << b << '\n';
    }
}