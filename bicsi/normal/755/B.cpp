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

const int kMaxN = 500000;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	int n, m;
	cin >> n >> m;

	vector<string> w[2] = {vector<string>(n), vector<string>(m)};
	map<string, int> cnt;
	for(int i = 0; i < n; ++i) {
		cin >> w[0][i];
		cnt[w[0][i]] += 1;
	}

	for(int i = 0; i < m; ++i) {
		cin >> w[1][i];
		cnt[w[1][i]] += 1;
	}

	int com[2] = {0, 0}, uni[2] = {0, 0};
	for(int i = 0; i < 2; ++i) 
	for(auto s : w[i]) {
		if(cnt[s] == 2) {
			com[i] += 1;
		} else {
			assert(cnt[s] == 1);
			uni[i] += 1;
		}
	}

	int pl = 0;
	while(true) {
		if(uni[pl] == 0 && com[pl] == 0) {
			cout << (pl ? "YES" : "NO");
			return 0;
		}
		if(com[pl] == 0) uni[pl]--;
		else {com[0]--; com[1]--;}

		pl = !pl;
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/