#include <bits/stdc++.h>

using namespace std;
int M[17], R[17];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> M[i];
    for(int i = 1; i <= n; ++i) cin >> R[i];

    int cnt = 0;
    for(int i = 0 ; i < 720720; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i % M[j] == R[j]) {
                cnt += 1;
                break;
            }
        }
    }

    cout << fixed << setprecision(10) << 1.0 * cnt / 720720;

    return 0;
}