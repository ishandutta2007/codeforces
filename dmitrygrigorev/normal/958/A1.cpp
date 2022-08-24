#include <bits/stdc++.h>
#define int long long
using namespace std;
char a[10][10], b[10][10];
int n;
void check(){
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) if (a[i][j] != b[i][j]) return;
    cout << "Yes" << endl;
    exit(0);
}
void rotate_90(){
    int c[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) c[i][j] = a[j][i];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) a[i][j] = c[i][j];
}
void inverse(){
    int c[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) c[i][j] = a[n-i-1][j];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) a[i][j] = c[i][j];
}
void inv(){
    int c[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) c[i][j] = a[i][n-j-1];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) a[i][j] = c[i][j];
}
signed main() {
    cin >> n;
    for (int i=0;i<n;i++) for (int j=0; j < n; j++) cin >> a[i][j];
    for (int i=0;i<n;i++) for (int j=0; j < n; j++) cin >> b[i][j];
    for (int i=0; i < 4; i++){
        check();
        rotate_90();
    }
    inverse();
    for (int i=0; i < 4; i++){
        check();
        rotate_90();
    }
    inv();
    for (int i=0; i < 4; i++){
        check();
        rotate_90();
    }
    inverse();
    for (int i=0; i < 4; i++){
        check();
        rotate_90();
    }
    cout << "No" << endl;
    return 0;
}