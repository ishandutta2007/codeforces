#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define int long long
 
using ll = long long;
using namespace std;

int n, a[60];
ll T;
char s[100005];	

int32_t main() {
	scanf("%lld%lld%s", &n, &T, s);
	for (int i = 0; i < n - 2; ++i)
		a[s[i] - 'a']++;
	T += (1LL << (s[n - 2] - 'a')) - (1LL << (s[n - 1] - 'a'));
	if (T < 0) T = -T;

	ll all = 0;
	for (int i = 0; i < 26; ++i)
		all += 1LL * (1LL << i) * a[i];
	
	all -= T;
	
	if (all < 0) return !printf("No\n");
	
	T = all;
	
	ll have = 0;
	
	for (int i = 25; 0 <= i; --i)
		a[i + 1] = a[i];
	a[0] = 0;
	
	for (int i = 0; i < 60; ++i) {
		have += a[i];
		if (T >> i & 1) {
			if (have == 0)
				break;
			have--;
			T -= (1LL << i);
		}
		have >>= 1;	
	}
	if (!T) 
		return !printf("Yes\n");
	printf("No\n");
	return 0;
}