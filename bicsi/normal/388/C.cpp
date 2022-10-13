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

vector<int> Vals[105];


int main() {	
//	assert(freopen("input.txt", "r", stdin));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c, x;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> c;
		while(c--) {
			cin >> x;
			Vals[i].push_back(x);
		}
	}

	int scoreTop = 0, scoreBottom = 0;

	vector<int> Extra;
	for(int i = 1; i <= n; ++i) {
		for(int a = 0, b = Vals[i].size() - 1; a <= b; ++a, --b) {
			if(a == b) {
				Extra.push_back(Vals[i][a]);
			} else {
				scoreBottom += Vals[i][a];
				scoreTop += Vals[i][b];
			}
		}
	}

	sort(Extra.rbegin(), Extra.rend());

	bool bit = 0;
	for(auto x : Extra) {
		if(bit) scoreTop += x;
		else scoreBottom += x;
		bit ^= 1;
	}

	cout << scoreBottom << " " << scoreTop << '\n';
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/