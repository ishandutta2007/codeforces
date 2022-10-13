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

	// Start code here

	int s, st, fn;
	cin >> s >> st >> fn;

	int ttram, tfoot;
	cin >> ttram >> tfoot;

	int ans = abs(fn - st) * tfoot;

	int xtram, dtram;
	cin >> xtram >> dtram;

	int cur_time = 0;
	while(xtram != st) {
		if(xtram == 0 && dtram == -1) dtram = 1;
		if(xtram == s && dtram == 1) dtram = -1;
		xtram += dtram;
		cur_time += ttram;
	}
	while(xtram != fn) {
		if(xtram == 0 && dtram == -1) dtram = 1;
		if(xtram == s && dtram == 1) dtram = -1;
		xtram += dtram;
		cur_time += ttram;
	}

	cout << min(ans, cur_time) << endl;



	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/