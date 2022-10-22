#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 1e6 + 5, BASE = 31, MOD = 1e9 + 9;
char s[MN];
int hsh[MN], pw[MN];
int substr (int l, int r) {
	int ret = hsh[r] - (ll)hsh[l-1] * pw[r-l+1] % MOD;
	return ret < 0 ? ret + MOD : ret;
}
int main () { 
	scanf ("%s",s+1);
	int n = strlen(s+1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = (ll)pw[i-1] * BASE % MOD;
		hsh[i] = ((ll)hsh[i-1] * BASE + s[i] - 'a' + 1) % MOD;
	}
	vector<int> cango;
	for (int i = 1; i < n; i++) if (substr(1,i) == substr(n-i+1,n)) cango.push_back(i);
	auto works = [&] (int mid) {
		mid = cango[mid];
		for (int i = 2; i + mid - 1 < n; i++) if (substr(1,mid) == substr(i,i+mid-1)) return true;
		return false;
	};
	int low = 0, high = (int)cango.size() - 1, mid, ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (works(mid)) low = (ans = mid) + 1;
		else high = mid - 1;
	}
	if (ans == -1) printf ("Just a legend\n");
	else {
		for (int i = 1; i <= cango[ans]; i++) printf ("%c",s[i]);
		printf ("\n");
	}
	return 0;
}