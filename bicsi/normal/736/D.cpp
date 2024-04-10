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

struct Line {
	bitset<2005> bs;
	bitset<2005> xors;
};
Line G[2005];
vector<pair<int, int>> Qry;
int n;

void Dump() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cerr << G[i].bs[j];
		cerr << endl;
	}
	cerr << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Start code here
	int m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		G[i].xors[i] = 1;
	}

	while(m--) {
		int a, b;
		cin >> a >> b;
		G[a - 1].bs[b - 1] = 1;

		Qry.emplace_back(a - 1, b - 1);
	}

	// Dump();

	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			if(G[j].bs[i] == 1) {
				swap(G[i], G[j]);
				break;
			}
		}

		assert(G[i].bs[i] == 1);
		for(int j = 0; j < n; ++j) {
			if(G[j].bs[i] == 1 && j != i) {
				G[j].bs ^= G[i].bs;
				G[j].xors ^= G[i].xors;
			}
		}

		// Dump();
	}

	for(auto p : Qry) {
		if(G[p.second].xors[p.first]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/