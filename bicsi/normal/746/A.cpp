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
// ?	freopen("input", "r", stdin);??	freopen("output", "w", stdout);

	// Start code here

	int a, b, c;
	cin >> a >> b >> c;

	int ans = min(a, b / 2);
	ans = min(ans, c / 4);

	cout << 7 * ans << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/