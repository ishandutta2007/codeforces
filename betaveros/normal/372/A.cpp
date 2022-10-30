#include <cstdio>
#include <vector>
#include <algorithm>
#define fori(i,s,e) for(int i = s; i < e; i++)
using namespace std;

int n;
vector<int> kangaroos;
void readInput() {
	scanf("%d", &n);
	fori (_, 0, n) {
		int a;
		scanf("%d", &a);
		kangaroos.push_back(a);
	}
}

bool canHide(int m) {
	fori (i, 0, m) {
		if (kangaroos[i] * 2 > kangaroos[n-m+i]) return false;
	}
	return true;
}

int best() {
	sort(kangaroos.begin(), kangaroos.end());
	// bin search, can hide lo, can't hide hi
	int lo = 0, hi = n/2 + 1;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (canHide(mid)) lo = mid; else hi = mid;
	}
	return n - lo;
}

int main() {
	readInput();
	printf("%d\n", best());
}