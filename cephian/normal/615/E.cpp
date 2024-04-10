#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll lev = sqrt(n/3);
	n -= 3*(lev*(lev-1));
	while(n >= 6*lev) {
		n-=6*lev;
		++lev;
	}
	int stage = n/lev;
	int mark = n%lev;
	ll x,y;
	if(stage == 0) {
		if(mark == 0) {
			x = 2*(lev-1);
			y = 0;
		} else {
			x = 2*lev;
			y = 0;
			x -= mark;
			y += 2*mark;
		}

	} else if(stage == 1) {
		x = lev;
		y = 2*lev;
		x -= 2* mark;
	} else if(stage == 2) {
		x = -lev;
		y = 2*lev;
		x -= mark;
		y -= 2*mark;
	} else if(stage == 3) {
		x = -2*lev;
		y = 0;
		x += mark;
		y -= 2*mark;
	} else if(stage == 4) {
		x = -lev;
		y = -2*lev;
		x += 2*mark;
		y += 0;
	} else if(stage == 5) {
		x = lev;
		y = -2*lev;
		x += mark;
		y += 2*mark;
	}
	cout << x << " " << y << "\n";

	return 0;
}