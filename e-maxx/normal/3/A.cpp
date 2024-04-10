#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {


	string a, b;
	cin >> a >> b;

	vector<string> ans;
	while (a != b) {
		int dx = 0,  dy = 0;
		if (a[0] < b[0])
			dx = 1;
		if (a[0] > b[0])
			dx = -1;
		if (a[1] < b[1])
			dy = 1;
		if (a[1] > b[1])
			dy = -1;
		string s = dx&&!dy ? (dx==1 ? "R" : "L") : dy&&!dx ? (dy==1 ? "U" : "D") : dx==1&&dy==1 ? "RU" : dx==-1&&dy==1 ? "LU" : dx==-1&&dy==-1 ? "LD" : "RD";
		ans.push_back (s);

		a[0] += dx,  a[1] += dy;
	}

	cout << ans.size() << endl;
	for (size_t i=0; i<ans.size(); ++i)
		cout << ans[i] << endl;

}