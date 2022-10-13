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

bool G[1024][1024];
int D[1024][1024];
int n;

int Solve() {
	int a[2] = {0, 0};
	
	for(int it = 0; it < 2; ++it) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				D[i][j] = (G[i][j] == it ? 1 : 1e9);

		for(int i = 0; i < n; ++i)
			D[i][i] = 0;

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				a[it] = max(a[it], D[i][j]);
	}

	if(a[0] > n || a[1] > n) return -1;
	int ret = min(a[0], a[1]);
	return ret;
}

int Test() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(j == i) G[i][j] = 0;
			else G[i][j] = G[j][i] = rand() % 2;
		}
	return Solve();
}

void SolveOK(int n, int k) {
	if(k == 3) {
	if(n < 4) {
		cout << -1 << endl;
		return;
	}
	vector<pair<int, int>> Sol;
	Sol.emplace_back(2, 3);
	for(int i = 4; i <= n; ++i) {
		Sol.emplace_back(1, i);
		Sol.emplace_back(i, 2);
	}

	cout << Sol.size() << endl;
	for(auto p : Sol) {
		cout << p.first << " " << p.second << '\n';
	}
} else {
	cout << n - 1 << endl;
	for(int i = 1; i < n; ++i)
		cout << i << " " << i + 1 << '\n';
}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	srand(time(0));

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here
	int k;
	cin >> n >> k;

	if(k != 2 && k != 3) {
		cout << "-1" << endl;
	} else {
		if(n >= 5) {
			SolveOK(n, k);
			return 0;
		}

		int it = 0;
		while(true) {
			if(Test() == k)
				break;
			cerr << "Iteration: " << ++it << endl;

			if(it >= 1000) {
				cout << -1 << endl;
				return 0;
			}
		}	

		vector<pair<int, int>> Ans;
		for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if(G[i][j])
				Ans.emplace_back(i + 1, j + 1);

		cout << Ans.size() << '\n';
		for(auto p : Ans) {
			cout << p.first << " " << p.second << '\n';
		}
	}


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/