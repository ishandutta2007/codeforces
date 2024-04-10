/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

map<pair<long long, int>, long long> Comp;
long long solmax(int k, long long n) {
	if(n < 0) return -1;
	if(k == 0) return 0;

	auto it = Comp.find({n, k});
	if(it != Comp.end()) {
		return it->second;
	}

	int c;
	long long ans = -1;
	for(c = 1; 1LL * c * c * c <= n; ++c);
	for(c--; c >= 1; c--) {
		long long ccub = 1LL * c * c * c;
		long long c1cub = 1LL * (c + 1) * (c + 1) * (c + 1);
		long long newn = min(n - ccub, c1cub - ccub - 1);

		if(newn + ccub <= ans) continue;

		long long qry = solmax(k - 1, newn);
		if(qry == -1) continue;
		
		ans = max(ans, qry + ccub); 
	}

	return Comp[{n, k}] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n;
	cin >> n;

	// Get minimum
	int use = 1, sol = 0;
	long long nown = 0;

	while(true) {
		long long ucub = 1LL * use * use * use;
		long long u1cub = 1LL * (use + 1) * (use + 1) * (use + 1);

		if(nown + ucub > n) break;
		if(nown + ucub >= u1cub) {
			use += 1;
			continue;
		}

		sol += 1;
		nown += ucub;
	}

	cout << sol << " " << solmax(sol, n) << endl;
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/