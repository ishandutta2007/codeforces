#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int X = t * ((n + k - 1) / k);
	int Y = 0;
	while (true) {
		++Y;
		int z = Y / t * k;
		z += (Y - d) / t * k;
		if (z >= n) break;
	}
	if (Y < X)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return false;
}

int main() {

    while (solve());
    
    return 0;
}