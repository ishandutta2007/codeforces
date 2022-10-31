#include <iostream>
#include <map>

using namespace std;

map<string,int> m;

int main() {
	ios::sync_with_stdio(0);
	m["Tetrahedron"] = 4;
	m["Cube"] = 6;
	m["Octahedron"] = 8;
	m["Dodecahedron"] = 12;
	m["Icosahedron"] = 20;
	int n,a=0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a += m[s];
	}
	cout << a << "\n";
}