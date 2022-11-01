#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

char map[6][34] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 4; i++) {
		if (n) {
			n--;
			map[i][1] = 'O';
		}
	}
	for(int c = 3; n; c += 2) {
		for(int r = 1; r <= 4; r++) {
			if (r == 3) {
				continue;
			}
			if (n) {
				n--;
				map[r][c] = 'O';
			}
		}
	}
	for(int i = 0; i < 6; i++) {
		printf("%s", map[i]);
		puts("");
	}
	return 0;
}