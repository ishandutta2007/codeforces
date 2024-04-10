#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n,m;
	bool bw = 0;
	cin >> n >> m;
	for(int i = n*m; i >=1; --i) {
		string s;
		cin >> s;
		if(s != "B" && s != "W" && s != "G") {
			cout << "#Color\n";
			return 0;
		}
	}
	cout << "#Black&White\n";
	return 0;
}