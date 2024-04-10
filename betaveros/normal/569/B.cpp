#include <cstdio>
#include <cassert>
using namespace std;
int n;
const int N = 100008;
bool seen[N];
int res[N];
int x;
int cnt;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &res[i]);
		if (res[i] > n || seen[res[i]]) {
			res[i] = 0;
		} else {
			seen[res[i]] = true;
		}
	}
	int nxt = 1;
	while (seen[nxt]) nxt++;
	for (int i = 0; i < n; i++) {
		if (res[i] == 0) {
			res[i] = nxt;
			nxt++;
			while (seen[nxt]) nxt++;
		}
	}
	assert(nxt == n + 1);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
}