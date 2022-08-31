#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n, k;
    cin >> n >> k;
    char matrix[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) cin >> matrix[i][j];
    int ans[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) ans[i][j] = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (matrix[i][j] == '#') continue;
            int A = 0, B = 0;
            for (int p=i-1; p >= 0; p--){
                if (matrix[p][j] == '#') break;
                A++;
            }
            for (int p=i+1; p < n; p++){
                if (matrix[p][j] == '#') break;
                B++;
            }
            for (int p=0; p < k; p++){
                if (p > A) continue;
                int vn = k - p - 1;
                if (vn > B) continue;
                ans[i][j]++;
            }
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (matrix[i][j] == '#') continue;
            int A = 0, B = 0;
            for (int p=j-1; p >= 0; p--){
                if (matrix[i][p] == '#') break;
                A++;
            }
            for (int p=j+1; p < n; p++){
                if (matrix[i][p] == '#') break;
                B++;
            }
            for (int p=0; p < k; p++){
                if (p > A) continue;
                int vn = k - p - 1;
                if (vn > B) continue;
                ans[i][j]++;
            }
        }
    }
    int res = -1, x=-1, y=-1;
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (ans[i][j] > res){
                res = ans[i][j];
                x = i+1, y=j+1;
            }
        }
    }
    cout << x << " " << y;
}