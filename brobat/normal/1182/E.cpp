#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

/*
[Fx Fx+1 Fx+2] = [c 2c^2 3c^3]*[[0, 0, 1],
                                [1, 0, 1],
                                [0, 1, 1]] ^ x.
x = n - 5
Then the powers are - 
A = (c * f1) ^ (Fx - 1)
B = (c^2 * f2) ^ (Fx+1 - 1)
C = (c^3 * f3) ^ (Fx+2 - 1)
Ans = ABC * (c^n)^-1 [Modulo inverse of c^n].
*/

// Finding exponents of f1 f2 and f2 - Using series F(x) = F(x-1) + F(x-2) + F(x-3).
// f1 is the (n - 3)rd term of the sequence (1, 1, 2, ...) 
// f2 is the (n - 3)rd term of the sequence (1, 2, 3, ...)
// f3 is the (n - 3)rd term of the sequence (1, 2, 4, ...)
// Find the matrix for the sequence F(x) = F(x-1) + F(x-2) + F(x-3).
// [Fx Fx+1 (Fx + Fx+1 + Fx-1)] = [Fx-1 Fx Fx+1] [Some 3*3 matrix]
// The 3*3 matrix will be - {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
// Take this matrix to the (n - 3)rd power.
// Now res is equal to P^(n - 3).

int n;
vector<vector<int>> P(3, vector<int>(3));
vector<vector<int>> res(3, vector<int>(3));

void multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> prod(3, vector<int>(3));
    forn(i, 0, 3) forn(j, 0, 3) prod[i][j] = 0;
    forn(i, 0, 3) forn(j, 0, 3) forn(k, 0, 3) {
        prod[i][j] = (prod[i][j] + (a[i][k]*b[k][j])) % (MOD - 1);
    }
    forn(i, 0, 3) forn(j, 0, 3) a[i][j] = prod[i][j];
}

void binpow(int x) {
    while(x > 0) {
        if(x & 1) multiply(res, P);
        multiply(P, P);
        x >>= 1;
    }
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res%MOD;
}
void solve() {
    int arr[3][3] = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
    forn(i, 0, 3) forn(j, 0, 3) P[i][j] = arr[i][j];
    forn(i, 0, 3) forn(j, 0, 3) {
        if(i==j) res[i][j] = 1;
        else res[i][j] = 0;
    }
    cin >> n;
    binpow(n - 3);
    int e1 = res[0][2];
    int e2 = res[1][2];
    int e3 = res[2][2];
    // cerr << e1 << " " << e2 << " " << e3 << endl;
    int f1, f2, f3, c;
    cin >> f1 >> f2 >> f3 >> c;
    int ans = binpow(f1 * c % MOD, e1) * binpow(f2*c%MOD*c%MOD, e2) % MOD * binpow(f3*c%MOD*c%MOD*c%MOD, e3) % MOD;
    // cout << ans << endl;
    int div = binpow(c, n);
    div = binpow(div, MOD - 2);
    cout << ans * div % MOD;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}