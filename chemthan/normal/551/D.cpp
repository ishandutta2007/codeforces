#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmat = 3;
ll n, k, l, m;
ll f, g;

struct matrix {
       ll x[nmat][nmat];
       matrix() {ms(x, 0);}
};

matrix mul(matrix A, matrix B) {
       matrix res;
       FOR(i, 0, nmat) FOR(j, 0, nmat) FOR(k, 0, nmat) res.x[i][j] = (res.x[i][j] + A.x[i][k] * B.x[k][j]) % m;
       return res;
}

matrix ex(matrix A, ll k) {
       if (k == 1) return A;
       if (k & 1) return mul(ex(A, k - 1), A);
       matrix T = ex(A, k >> 1);
       return mul(T, T);
}

void run() {
     matrix mat;
     mat.x[0][0] = 1; mat.x[0][1] = 1; mat.x[0][2] = 0;
     mat.x[1][0] = 1; mat.x[1][1] = 0; mat.x[1][2] = 0;
     mat.x[2][0] = 1; mat.x[2][1] = 0; mat.x[2][2] = 2;
     if (n == 2) {f = 3; g = 1; return;}
     if (n == 3) {f = 5; g = 3; return;}
     mat = ex(mat, n - 3);
     f = (5 * mat.x[0][0] + 3 * mat.x[1][0]) % m;
     g = (3 * mat.x[0][0] + 1 * mat.x[1][0] + 4 * mat.x[2][0]) % m;
}

void solve() {
     scanf("%I64d%I64d%I64d%I64d", &n, &k, &l, &m);
     if (l < 64 && k >= 1ULL << l) {cout<<0; return;}
     run();
     ll ans = 1;
     FOR(i, 0, l) {if (k % 2 == 0) ans = (ans * f) % m; else ans = (ans * g) % m; k /= 2;}
     printf("%I64d", ans % m);
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
      solve();
      return 0;
}