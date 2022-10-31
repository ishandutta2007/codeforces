#include <bits/stdc++.h>
using namespace std;

map<string,string> M;

int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		string a,b;
		cin >> a >> b;
		if(a.size() <= b.size()) b = a;
		M[a] = b;
	}
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		cout << M[s] << " ";
	}
	cout << "\n";
}