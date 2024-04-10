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

bitset<512> Can[512];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	Can[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;

		for(int j = k - x; j >= 0; --j) {
			Can[j + x] |= Can[j];
			Can[j + x] |= (Can[j] << x);
		}
	}

	vector<int> Sol;
	for(int x = 0; x <= k; ++x)
		if(Can[k][x])
			Sol.push_back(x);
	
	cout << Sol.size() << '\n';
	for(auto x : Sol) cout << x << " ";
	cout << endl;
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/