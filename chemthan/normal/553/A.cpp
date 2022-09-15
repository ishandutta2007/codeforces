#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 1010;
const int mod = 1000000007;
int k;
int a[maxn];
ll C[maxn][maxn];
bool isprime[1000100];
vi prime;

ll mu(ll x, ll k){
	if(k == 0) return 1;
	if(k & 1) return mu(x, k - 1) * x % mod;
	ll t = mu(x, k >> 1);
	return t * t % mod;
}

ll combine(int a, int b) {
   if (a > b) return 0;
   if (a == 0 || a == b) return 1;
   ll ans = 1;
   FOR(i, 0, sz(prime)) {
       int pow = prime[i];
       int cnt = 0;
       while (b >= pow) {
             cnt += b / pow - (a / pow) - ((b - a) / pow);
             pow *= prime[i];
       }
       ans = ans * mu(prime[i], cnt) % mod;
   }
   return ans;
}

void solve() {
     ms(C, 0);
     scanf("%d", &k);
     FOR(i, 0, k) scanf("%d", a + i);
     ms(isprime, 0);
     isprime[1] = 0;
     for (int i = 2; i * i < 1000100; i++) {
         if (!isprime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j < 1000100; j += i) isprime[j] = 1;
         }
     }
     ll ans = 1;
     ll cursum = 0;
     FOR(i, 0, k) {
            cursum += a[i];
            ans = ans * combine(a[i] - 1, cursum - 1) % mod;
     }
     printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}