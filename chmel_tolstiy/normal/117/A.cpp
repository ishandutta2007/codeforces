#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m;
    M = 2 * m - 2;
    for (int i = 0; i < n; i++) {
         int t, s, f;
         cin >> s >> f >> t;
         int r = 1e9;
         if (s == f) r = t;
         else {
             int T = s-1 + (t - (s-1) + M - 1)/M * M;

             if (f >= s) r = min(r, T + f - s);
             else r = min(r, T + m - s + m - f);

             T = s-1 + (t - (s-1) + M - 1)/M * M + 2*(m-s);
             if (T - M >= t) T -= M;

             if (f <= s) r = min(r, T + s - f);
             else r = min(r, T + (s-1)+(f-1));
         }

         cout << r << endl;
    }
    return 0;
}