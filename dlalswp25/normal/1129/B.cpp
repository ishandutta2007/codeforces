#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int s;
int K;

const int X = 1000000;

int main() {
	scanf("%d", &K);
	if(K & 1) {
		ans.push_back(1);
		ans.push_back(-2);
		K += 1999; K /= 2;
		while(K >= X) {
			ans.push_back(X);
			K -= X;
		}
		ans.push_back(K);
		while(ans.size() < 1999) ans.push_back(0);
	}
	else {
		ans.push_back(1);
		ans.push_back(-2);
		K += 2000; K /= 2;
		while(K >= X) {
			ans.push_back(X);
			K -= X;
		}
		ans.push_back(K);
		while(ans.size() < 2000) ans.push_back(0);
	}
	printf("%d\n", ans.size());
	for(int i : ans) printf("%d ", i);
	puts("");
	return 0;
}