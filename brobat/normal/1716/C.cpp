#include <bits/stdc++.h>
using namespace std;

/*
  I wish to store 2 values:
    in[i][j] --> The minimum time to reach (i, j) from (0, 0), assuming we go in a ziz-zag manner, starting at t = 0
    out[i][j] --> The time taken to reach (i ^ 1, j) from (i, j), assuming we go in circular manner, starting at t = 0
  The answer would be max(out[i][j], in[i][j] + dist) where dist is the distance between (i, j) and (i ^ 1, j). 
  Only valid for those (i, j) that give i + j == Even. 
*/

const int N = 200100;
int a[2][N], in[2][N], out[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        in[0][0] = 0;
        int i = 1, j = 0; 
        while(j < n) {
            if((i + j) % 2) {
                // Move right.
                in[i][j] = max(in[i ^ 1][j], a[i][j]) + 1;
                j++;
            } else {
                // Move up or down.
                in[i][j] = max(in[i][j - 1], a[i][j]) + 1;
                i ^= 1;
            }
        }
        // for(int i = 0; i < 2; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << in[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        int ans = in[i][n - 1];
        // cout << ans << '\n';
        for(int i = 0; i < 2; i++) {
            out[i][n - 1] = a[i ^ 1][n - 1] + 1;
        }
        for(int j = n - 2; j >= 0; j--) {
            for(int i = 0; i < 2; i++) {
                int dist = 2*(n - 1 - j) + 1;
                out[i][j] = a[i][j + 1] + 1; // reach (i, j + 1)
                out[i][j] = max(out[i][j] + dist - 2, out[i][j + 1]); // reach(i ^ 1, j + 1)
                out[i][j] = max(out[i][j], a[i ^ 1][j]) + 1; // reach(i ^ 1, j)
            }
        }
        // for(int i = 0; i < 2; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << out[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                if((i + j) % 2 == 0) {
                    int dist = 2*(n - 1 - j) + 1;
                    ans = min(ans, max(in[i][j] + dist, out[i][j]));
                } 
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}