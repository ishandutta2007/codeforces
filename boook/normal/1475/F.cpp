#include <bits/stdc++.h>
using namespace std;
#define maxn 1010


int t, n, x[maxn][maxn];
string s[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                x[i][j] = 0;

        for (int i = 0; i < n; ++ i) cin >> s[i];
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) 
                if (s[i][j] == '1') x[i + 1][j + 1] ^= 1;
        for (int i = 0; i < n; ++ i) cin >> s[i];
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j) 
                if (s[i][j] == '1') x[i + 1][j + 1] ^= 1;
        
        for (int i = 2; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (x[1][j] == 1) x[i][j] ^= 1;
            }
        }
        int ok = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (x[i][j] != x[i][1]) ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}