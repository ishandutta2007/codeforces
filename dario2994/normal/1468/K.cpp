#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif


void move(int& x, int& y, char c) {
	if (c == 'L') x--;
	if (c == 'R') x++;
	if (c == 'D') y--;
	if (c == 'U') y++;
}

void undomove(int& x, int& y, char c) {
	if (c == 'L') x++;
	if (c == 'R') x--;
	if (c == 'D') y++;
	if (c == 'U') y--;
}


pair<int,int> solve() {
	string s;
	cin >> s;
	set<pair<int,int>> trovati;
	int x = 0, y = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		move(x, y, s[i]);
		if (trovati.find({x, y}) != trovati.end()) continue;
		trovati.insert({x, y});
		int ax = x, ay = y;
		undomove(ax, ay, s[i]);
		for (int j = i+1; j < int(s.size()); j++) {
			move(ax, ay, s[j]);
			if (ax == x and ay == y) undomove(ax, ay, s[j]);
		}
		if (ax == 0 and ay == 0) return {x, y};
	}
	return {0, 0};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        pair<int,int> pp = solve();
        cout << pp.first << " " << pp.second << "\n";
    }
}