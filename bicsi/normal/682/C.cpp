/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]:\t\t";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

#define int long long

const int kMaxN = 200000;


int A[kMaxN], Parent[kMaxN], Cost[kMaxN];
bool Comp[kMaxN];
int Min[kMaxN];
bool Bad[kMaxN];

void Solve(int i) {
	if(Comp[i]) return;
	Comp[i] = true;

	Solve(Parent[i]);
	Cost[i] += Cost[Parent[i]];
	Min[i] = min(Cost[i], Min[Parent[i]]);

	if(Bad[Parent[i]] || Min[i] < Cost[i] - A[i])
		Bad[i] = true;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];
	}
	for(int i = 2; i <= n; ++i)
		cin >> Parent[i] >> Cost[i];

	Comp[1] = 1;
	Min[1] = 0;
	for(int i = 2; i <= n; ++i)
		Solve(i);

	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += Bad[i];

	cout << ans;

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/