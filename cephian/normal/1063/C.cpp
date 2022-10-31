#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int bsum[N][N] = {};
int best[N] = {};
int can_make[N*N] = {};

const double PI = atanl(1) * 4;
const int M = 1e9;

pair<int,int> get(double t) {
	double y = sin(t * PI) * M;
	double x = cos(t * PI) * M;
	return make_pair(int(x+0.5), int(y+0.5));
}

bool push(double t) {
	auto x = get(t);
	cout << x.first << " " << x.second << endl;
	string w;
	cin >> w;
	return w == "white";
}

int main() {
	int n;
	cin >> n;
	double lo = 0;
	double hi = 0.5;

	bool rt = push(hi);
	for(int i = 1; i < n; ++i) {
		bool b = push((lo+hi)/2);
		if(b == rt)
			hi = (lo+hi)/2;
		else
			lo = (lo+hi)/2;
	}
	cout << "0 0" << endl;
	auto x = get((lo+hi)/2);
	cout << x.first << " " << x.second << endl;
}