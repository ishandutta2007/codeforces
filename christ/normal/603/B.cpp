#include <bits/stdc++.h> 
using namespace std;
const int MN = 2e5 + 3, MOD = 1e9 + 7;
int main () {
	int p,k;
	scanf ("%d %d",&p,&k);
	if (!k) {
		int ret = 1, go = p;
		while (--go) ret = (long long)ret * p % MOD;
		return !printf ("%d\n",ret);
	}
	vector<int> par(p); iota(par.begin(),par.end(),0);
	auto find = [&] (int n, const auto &ref) -> int {
		return par[n] == n ? n : par[n] = ref(par[n],ref);
	};
	auto merge = [&] (int a, int b) {
		par[find(a,find)] = find(b,find);
	};
	for (int i = 1; i < p; i++) merge(i,(long long)i * k % p);
	int go = k==1, ret = 1;
	for (int i = 1; i < p; i++) if (par[i] == i) ++go;
	while (go--) ret = (long long)ret * p % MOD;
	printf ("%d\n",ret);
	return 0;
}