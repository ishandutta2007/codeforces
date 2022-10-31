#include <bits/stdc++.h>
using namespace std;

map<string,string> name;

int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string a,b;
		cin >> a >> b;
		name[b] = a;
	}
	for(int i = 0; i < m; ++i) {
		string a,b;
		cin >> a >> b;
		cout << a << " " << b << " " << "#" << name[b.substr(0,b.size()-1)] << "\n";
	}
}