#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e3+5;
int n;
int x[N];
int y[N];

inline int mod2(int x) {
	if(x < 0) return (-x) % 2;
	return x % 2;
}

bool reduce() {
	bool ee = false, oo = false, eo = false, oe = false;
	for(int i = 0; i < n; ++i) {
		bool a = mod2(x[i]);
		bool b = mod2(y[i]);
		ee += !a && !b;
		oo += a && b;
		eo += !a && b;
		oe += a && !b;
	}
	if((ee||oo) && (eo || oe)) return true;
	// oe
	if(!ee && !oo && !eo)
		for(int i = 0; i < n; ++i) x[i] = (x[i]+1)/2, y[i] = y[i]/2;
	// eo
	else if(!ee && !oo && !oe)
		for(int i = 0; i < n; ++i) x[i] = x[i]/2, y[i] = (y[i]+1)/2;
	// ee
	else if(!eo && !oo && !oe)
		for(int i = 0; i < n; ++i) x[i] = x[i]/2, y[i] = y[i]/2;
	// oo
	else if(!eo && !ee && !oe)
		for(int i = 0; i < n; ++i) x[i] = (x[i]+1)/2, y[i] = (y[i]+1)/2;
	else {
		for(int i = 0; i < n; ++i) {
			int a = x[i];
			int b = y[i];
			x[i] = a+b;
			y[i] = a-b;
		}
	}
	return false;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	while(!reduce());
	vector<int> A;
	for(int i = 0; i < n; ++i) {
		if(mod2(x[i]) == mod2(y[i]))
			A.push_back(i+1);
	}

	cout << A.size() << '\n';
	for(int x : A)
		cout << x << ' ';
	cout << endl;
}