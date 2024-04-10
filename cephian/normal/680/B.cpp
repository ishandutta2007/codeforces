#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
map<int,int> p;

int main() {
	int n,a;
	cin >> n >> a;
	for(int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		if(c) ++ m[abs(i-a)];
		++p[abs(i-a)];
	}
	a = 0;
	for(auto x : m) {
		if(x.second == p[x.first]) a += p[x.first];
	}
	cout << a << "\n";
}