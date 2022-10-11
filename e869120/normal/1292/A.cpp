#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, Q; bool I[3][1000009];
int cnt = 0;

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= Q; i++) {
		int px, py; scanf("%d%d", &px, &py);

		if (I[1][py] == true && I[2][py] == true) cnt--;
		if (px == 1) {
			if (I[2][py - 1] == true && I[1][py] == true) cnt--;
			if (I[2][py + 1] == true && I[1][py] == true) cnt--;
		}
		if (px == 2) {
			if (I[1][py - 1] == true && I[2][py] == true) cnt--;
			if (I[1][py + 1] == true && I[2][py] == true) cnt--;
		}

		I[px][py] ^= true;

		if (I[1][py] == true && I[2][py] == true) cnt++;
		if (px == 1) {
			if (I[2][py - 1] == true && I[1][py] == true) cnt++;
			if (I[2][py + 1] == true && I[1][py] == true) cnt++;
		}
		if (px == 2) {
			if (I[1][py - 1] == true && I[2][py] == true) cnt++;
			if (I[1][py + 1] == true && I[2][py] == true) cnt++;
		}

		if (cnt == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}