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

#define int long long

int Norm(int x) {
	int ret = 0;
	int i = 1;
	while(x) {
		ret += (x % 10 % 2) * i;
		x /= 10;
		i *= 2;
	}
	return ret;
}

int Cnt[1000005];

void Insert(int x) {
	Cnt[Norm(x)] += 1;
}
void Erase(int x) {
	Cnt[Norm(x)] -= 1;
}

int Query(int x) {
	return Cnt[Norm(x)];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--) {
		char c;
		int x;
		cin >> c >> x;
		if(c == '+') Insert(x);
		if(c == '-') Erase(x);
		if(c == '?') cout << Query(x) << '\n';
/*
		int ans = Norm(x);
		for(int i = 0; i < 18; ++i, ans /= 2)
			cerr << (ans % 2);
		cerr << endl;
*/
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/