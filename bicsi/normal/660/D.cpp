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

int main() {	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> X(n), Y(n);
	for(int i = 0; i < n; ++i) {
		cin >> X[i] >> Y[i];
	}

	vector<pair<int, int>> V;
	V.reserve(n * n);

	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
		if(i != j)
			V.emplace_back(X[j] - X[i], Y[j] - Y[i]);

	sort(V.begin(), V.end());
	
	int cnt = 0;
	long long total = 0;

	for(int i = 1; i < V.size(); ++i) {
		if(V[i] == V[i - 1]) {
			total += (++cnt);
		} else {
			cnt = 0;
		}
	}
	
	cout << total / 4 << '\n';
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/