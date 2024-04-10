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




int Ans[5000];
int n;
void Ask(vector<int> Indices) {
	if(Indices.empty()) return;
	cout << Indices.size() << endl;
	for(auto x : Indices) cout << x << " ";
	cout << endl;

	for(int i = 1; i <= n; ++i) {
		int rd;
		cin >> rd;
		if(binary_search(Indices.begin(), Indices.end(), i) == false)
			Ans[i] = min(Ans[i], rd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
		Ans[i] = 2e9;

	int step;
	for(step = 1; step <= n; step *= 2);
	for(step /= 2; step; step /= 2) {
		vector<int> Indices[2];
		int cur = 0;
		for(int i = 1; i <= n; ++i) {
			Indices[cur].push_back(i);
			if(i % step == 0) cur = !cur;
		}

		Ask(Indices[0]);
		Ask(Indices[1]);
	}

	cout << -1 << endl;
	for(int i = 1; i <= n; ++i)
		cout << Ans[i] << " ";
	cout << endl;




	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/