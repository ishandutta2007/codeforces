#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m,k;

vi vx,vy;
vvi x,y;

void fl() {
	x.push_back(vx);
	y.push_back(vy);
	vx.clear();
	vy.clear();
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> m >> k;

	for(int r = 0; r < n; ++r) {
		int s,e,i;
		if(r&1) {
			s = 0;
			e = m;
			i = 1;
		} else {
			s = m-1;
			e = -1;
			i = -1;
		}
		for(int c = s; c != e; c += i) {
			vx.push_back(r+1);
			vy.push_back(c+1);
			if(vx.size() == 2 && x.size() < k-1)
				fl();
		}
	}
	fl();
	for(int i = 0; i < k; ++i) {
		cout << x[i].size();
		for(int j = 0; j < x[i].size(); ++j)
			cout << " " << x[i][j] << " " << y[i][j];
		cout << "\n";
	}

	return 0;
}