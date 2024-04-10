/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x"[]: ";\
	for(int _=1;_<=n;++_) cerr<<x[_]<<" ";cerr<<'\n';}

/*************************************************************/

const int MAXN = 105;
int V[MAXN];
multiset<int> Set;

int main() {	
//	assert(freopen("input.txt", "r", stdin));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n, val;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> V[i];
	}

	sort(V + 1, V + n + 1);

	int ans = 1;
	Set.insert(1);
	for(int i = 2; i <= n; ++i) {
		auto it = Set.upper_bound(V[i]);
		if(it == Set.begin()) {
			Set.insert(1);
			ans += 1;
		} else {
			--it;
			Set.insert(*it + 1);
			Set.erase(it);
		}
	}


	cout << ans;

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/