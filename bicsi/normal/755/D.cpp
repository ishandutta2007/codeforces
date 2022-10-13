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

const int kMaxN = 2000000;

int n;

int T[kMaxN];
int Add(int pos) {
	for(++pos; pos <= n; pos += (pos & -pos)) {
		T[pos] += 1;
	}
}
int Sum(int pos) {
	int ret = 0;
	for(++pos; pos > 0; pos -= (pos & -pos))
		ret += T[pos];
	return ret;
}
int Sum(int a, int b) {
	if(b >= a) 
		return Sum(b) - Sum(a - 1);
	return Sum(a, n - 1) + Sum(0, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here
	int k;
	cin >> n >> k;
    
    k = min(k, n - k);
	long long acc = 1;
	int now = 0;

	for(int i = 0; i < n; ++i) {

		int prev = now - k + 1;
		int nxt = now + k - 1;

		if(prev < 0) prev += n;
		if(nxt >= n) nxt -= n;

		acc += 1 + Sum(prev, nxt);
		Add(now);
		now += k;
		now %= n;

		cout << acc << ' ';
	}


	return 0;
}