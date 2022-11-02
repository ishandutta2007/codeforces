#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 110
#define mod 1000000007

vector<vector<int>> operator * (vector<vector<int>> a, vector<vector<int>> b) {
    int nn = a.size();
    vector<vector<int>> c(nn, vector<int>(nn, 0));
    for (int i = 0; i < nn; ++ i) {
        for (int k = 0; k < nn; ++ k) {
            for (int j = 0; j < nn; ++ j) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

int inv(int a, int k) {
    if (k == 0) return 1;
    else if (k % 2 == 0) return inv(a * a % mod, k >> 1);
    else if (k % 2 == 1) return inv(a * a % mod, k >> 1) * a % mod;
}

vector<vector<int>> ppow(vector<vector<int>> a, int k) {
    if (k == 1) return a;
    else if (k % 2 == 0) return ppow(a * a, k >> 1);
    else if (k % 2 == 1) return ppow(a * a, k >> 1) * a;
}

int n, k, x[maxn];
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> x[i];

    int zero = 0;
    for (int i = 1; i <= n; ++ i) zero += x[i] == 0;
    if (zero == 0) return cout << 1 << endl, 0;

    vector<vector<int>> a(zero + 1, vector<int>(zero + 1, 0));
    for (int i = 0; i <= zero; ++ i) {
        int all = n * (n - 1) / 2;
        int add = (zero - i) * (zero - i);
        int str = i * (n - zero - zero + i);
        if (i - 1 >= 0) a[i - 1][i] = str;
        if (i + 1 <= zero) a[i + 1][i] = add;
        a[i][i] = all - str - add;
    }
//    for (int i = 0; i <= zero; ++ i) {
//        for (int j = 0; j <= zero; ++ j) {
//            cout << a[i][j] << " ";
//        } cout << endl;
//    }
    a = ppow(a, k);
//    for (int i = 0; i <= zero; ++ i) {
//        for (int j = 0; j <= zero; ++ j) {
//            cout << a[i][j] << " ";
//        } cout << endl;
//    }

    int cnt = 0;
    for (int i = 1; i <= zero; ++ i) cnt += x[i] == 0;

    int v1 = a[zero][cnt], v2 = 0;
    for (int i = 0; i <= zero; ++ i) 
        v2 = (v2 + a[i][cnt]) % mod;

    cout << v1 * inv(v2, mod - 2) % mod << endl;
    return 0;
}