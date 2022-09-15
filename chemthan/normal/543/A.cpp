#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int n, m, b, mod;
int a;
ll f[501][501];

void solve(){
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    FOR(i, b + 1) f[0][i] = 1;
    while (n--) {scanf("%d", &a); FOR2(i, 1, m + 1) FOR2(j, a, b + 1) {f[i][j] += f[i - 1][j - a]; if (f[i][j] >= mod) f[i][j] -= mod;}}
    cout<<f[m][b];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}