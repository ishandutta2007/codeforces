#include <bits/stdc++.h>
//#include <iostream>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int nmax = 5000001;
int t, a, b;
bool isprime[5000001];
vector<int> prime;
int d[5000001];

void solve() {
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ms(isprime, 1); isprime[0] = isprime[1] = 0; for(int i = 2; i * i < nmax; i++) {if (isprime[i]) {for (int j = i * i; j < nmax; j += i) isprime[j] = 0; prime.push_back(i);}}
    ms(d, 0); d[1] = 0; FOR2(i, 2, nmax) {if (isprime[i]) {d[i] = 1; continue;} FOR(j, sz(prime)) {if (prime[j] * prime[j] > i) break; if (i % prime[j] == 0) {d[i] = d[i / prime[j]] + 1; break;}}}
    FOR2(i, 2, nmax) d[i] += d[i - 1];
    scanf("%d", &t); while (t--) {scanf("%d%d", &a, &b); printf("%d\n", d[a] - d[b]);}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}