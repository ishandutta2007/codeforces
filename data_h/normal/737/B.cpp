#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const int N = 2e5 + 7;

int n, a, b, k;
char s[N];

int main() {
	scanf("%d %d %d %d", &n, &a, &b, &k);
	scanf("%s", s + 1);
	vector<int> pos;
	pos.push_back(0); 
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') pos.push_back(i);
	}
	pos.push_back(n + 1);
	vector<int> shoot;
	for (int i = 0; i + 1 < pos.size(); i++) {
		for (int j = pos[i] + b; j < pos[i + 1]; j += b) {
			shoot.push_back(j);
		}
	}
	
	for (int i = 1; i < a && shoot.size(); i++) {
		shoot.pop_back();
	}
	printf("%d\n", (int)shoot.size());
	for (int i = 0; i < shoot.size(); i++) {
		printf("%d%c", shoot[i], i + 1 == shoot.size() ? '\n' : ' ');
	}
	return 0;
}