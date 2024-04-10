#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 111;

int sm[N];
char table[N][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", table[i]);
	}
	int answer = 0;
	int c = strlen(table[0]);
	for(int col = 0; col < c; col++) {
		bool rem = false;
		for(int j = 0; j < n - 1; j++) {
			if (sm[j] == 0 && table[j][col] > table[j + 1][col]) {
				rem = true;
			}
		}
		if (rem) {
			answer++;
			continue;
		}
		for(int j = 0; j < n - 1; j++) {
			sm[j] |= table[j][col] < table[j + 1][col];
		}
	}
	printf("%d\n", answer);
	return 0;
}