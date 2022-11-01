#include <iostream>

using namespace std;

const int N = 30;
char tile[2][N], s[N], t[N];
int n = 27, L = 13;
bool visit[10000];

int main() {
	scanf("%s", t);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i] == t[j]) {
				if (i + 1 == j) {
					puts("Impossible");
					return 0;
				}
				for (int k = 0; k < n; k++) {
					s[k] = t[(k + i) % n];
				}
				for (int k = 0; k < n; k++) {
					t[k] = s[k];
				}
				int delta = 0;
				int len = j - i - 1;
				if (len % 2 == 0) {
					delta = L - 1 - len / 2;
				} else {
					delta = L - (len + 1) / 2;
				}
				for (int k = 0; k < n; k++) {
					s[(k + delta) % n] = t[k];
				}
				int ptr = 0;
				for (int k = 0; k < L; k++) {
					if (visit[s[ptr]]) ptr++;
					visit[s[ptr]] = 1;
					tile[0][k] = s[ptr++];
				}
				for (int k = 0; k < L; k++) {
					if (visit[s[ptr]]) ptr++;
					visit[s[ptr]] = 1;
					tile[1][L - k - 1] = s[ptr++];
				}
				tile[0][L] = tile[1][L] = 0;
				puts(tile[0]);
				puts(tile[1]);
				return 0;
			}
		}
	}
	return 0;
}