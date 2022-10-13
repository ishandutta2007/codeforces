/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(long long _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

map<long long, long long> Cost;
void update(long long a, long long b, long long c) {
	

	while(a != b) {
		//cerr << a << " " << b << '\n';
		if(a > b) {
			Cost[a] += c;
			a /= 2;
		} else {
			Cost[b] += c;
			b /= 2;
		}
	}
	//cerr << '\n';
}

long long query(long long a, long long b) {
	long long s = 0;

	while(a != b) {
		//cerr << a << " " << b << '\n';
		if(a > b) {
			s += Cost[a];
			a /= 2;
		} else {
			s += Cost[b];
			b /= 2;
		}
	}
	//cerr << '\n';

	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long q, t, a, b, c;
	cin >> q;

	while(q--) {
		cin >> t;
		if(t == 1) {
			cin >> a >> b >> c;
			update(a, b, c);
		} else {
			cin >> a >> b;
			cout << query(a, b) << '\n';
		}
	}
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/