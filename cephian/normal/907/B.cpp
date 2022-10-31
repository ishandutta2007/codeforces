#include <bits/stdc++.h>

using namespace std;

string g[9] = {"","","","","","","","",""};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i = 0; i < 9; ++i) {
		string s;
		for(int j = 0; j < 3; ++j) {
			cin >> s;
			g[i] += s;
		}
	}
	int x,y;
	cin >> x >> y, --x, --y;
	x = (x%3)*3, y = (y%3)*3;
	bool full = true;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(g[x+i][y+j] == '.') {
				full = false;
				g[x+i][y+j] = '!';
			}
		}
	}
	if(full) {
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				if(g[i][j] == '.')
					g[i][j] = '!';
			}
		}
	}
	for(int i = 0; i < 9; ++i) {
		cout << g[i].substr(0,3) << " " << g[i].substr(3,3) << " " << g[i].substr(6,3) << "\n";
		if(i%3 == 2) cout << "\n";
	}

}