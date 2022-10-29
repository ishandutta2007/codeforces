#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;
	
	vector<char> u (n);
	int cur = 0;
	for (int i=0; i<5000000; ++i) {
		u[cur] = true;
		cur = (cur + i) % n;
	}

	puts (find (u.begin(), u.end(), 0) == u.end() ? "YES" : "NO");

}