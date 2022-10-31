#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n,m;
int g[100][100];

bool ok(int d) {
	if(d == 0) return 1;
	if((n%(1<<d)) != 0) return 0;
	int s = n/(1<<d);
	for(int i = 0; i < s; ++i)
		for(int j = 0; j < m; ++j)
			if(g[i][j] != g[s*2-1-i][j]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	int d = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> g[i][j];
	while(ok(d))
		++d;
	cout << n/(1<<(d-1)) << "\n";
	return 0;
}