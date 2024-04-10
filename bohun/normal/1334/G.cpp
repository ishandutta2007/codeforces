#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;
 
const int nax = 2e5 + 10; 
 
int p[26];
char s[nax], t[nax];
bitset <nax> f[26], res;
 
int main() {
	rep(i, 0, 25) {
		scanf ("%d", p + i);
		p[i]--;
	}
	scanf ("%s", s);
	scanf ("%s", t);
	int n = strlen(s), m = strlen(t);
	rep(i, 0, m - 1) 
		f[t[i] - 'a'][i] = 1;
	res.set();
	rep(i, 0, n - 1) {
		res &= (f[s[i] - 'a'] | f[p[s[i] - 'a']]) >> i;
	}
	rep(i, 0, m - n) {
		printf (res[i] ? "1" : "0");
	}
	
    return 0;
}