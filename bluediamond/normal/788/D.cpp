#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;

int ask(int x, int y) {
	cout << "0 " << x << " " << y << endl;
	int ret;
	cin >> ret;
	return ret;
}

const int INF = (int)1e8;
set<int> xys;

int tt = 0;
bool is;
void rec(int l, int r) {
	if (r - l - 1 <= 0) {
		return;
	}
	int midpoint = (l + r) / 2;
	int dmin = ask(midpoint, midpoint);
	vector<int> pot;
	
	if (dmin == 0) {
		pot.push_back(midpoint);
	}
	else {
		if (midpoint - dmin > l) pot.push_back(midpoint - dmin);
		if (midpoint + dmin < r) pot.push_back(midpoint + dmin);
	}

	if (pot.empty()) return;
	if (ask(pot[0], pot[0]) > 0) {
		if ((int)pot.size() == 1) return;
		pot[0] = pot[1];
	}
	if (ask(pot[0], pot[0]) != 0) return;
	midpoint = pot[0];
	xys.insert(midpoint);
	rec(l, midpoint);
	rec(midpoint, r);
}

signed main() {

	{
		int leftmost = -INF + ask(-INF, -INF);
		int rightmost = +INF - ask(+INF, +INF);
		xys.insert(leftmost);
		xys.insert(rightmost);
		is = (leftmost != -3);
		rec(leftmost, rightmost);
	}

	int mex = 0;
	while (xys.count(mex)) mex++;

	vector<int> ff, ss;

	for (auto& kek : xys) {
		if (ask(kek, mex) == 0) ff.push_back(kek);
		if (ask(mex, kek) == 0) ss.push_back(kek);
	}




	cout << 1 << " " << (int)ff.size() << " " << (int)ss.size() << endl;
	for (auto& x : ff) cout << x << " "; cout << endl;
	for (auto& x : ss) cout << x << " "; cout << endl;
}