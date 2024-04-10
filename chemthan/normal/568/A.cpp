#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 2000010;
ll p, q;
bool isprime[maxn];
int f[maxn];
int g[maxn];

bool checkpali(int n) {
	int k = 0; int a[10];
	while (n) {a[k++] = n % 10; n /= 10;}
	for (int i = 0; 2 * i < k; i++) if (a[i] != a[k - i - 1]) return false;
	return true;
}

void build() {
	ms(f, 0); ms(g, 0);
	ms(isprime, 1); g[1] = 1;
	for (ll i = 2; i < maxn; i++) {
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if (isprime[i]) {
			for (ll j = i * i; j < maxn; j += i) isprime[j] = 0;
			f[i]++;
		}
		if (checkpali(i)) g[i]++;
	}
}

void solve() {
	build();
	cin>>p>>q;
	FORd(i, maxn, 1) if (q * f[i] <= p * g[i]) {
		cout<<i; return;
	}
	cout<<"Palindromic tree is better than splay tree";
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}