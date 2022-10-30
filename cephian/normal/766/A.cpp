#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	string a,b;
	cin >> a >> b;
	if(a==b) cout << "-1\n";
	else cout << max(a.size(),b.size()) << endl;
	return 0;
}