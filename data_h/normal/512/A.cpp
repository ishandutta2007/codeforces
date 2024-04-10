#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int C = 26;
const int N = 222;

#define less LESS

int n;
int less[C][C], done[N];
char table[N][N];

int main() {
	memset(table, -1, sizeof(table));

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", table[i] + 1);
		table[i][strlen(table[i] + 1) + 1] = -1;
		for(int j = 1; table[i][j] != -1; j++) {
			table[i][j] -= 'a';
		}
	}
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j < n; j++) {
			if (!done[j]) {
				if (table[j][i] == table[j + 1][i]) {
					continue;
				} else {
					if (table[j][i] != -1 && table[j + 1][i] == -1) {
						puts("Impossible\n");
						return 0;
					} 
					done[j] = 1;
					if (table[j][i] == -1) {
						continue;
					}
					less[table[j][i]][table[j + 1][i]] = 1;
					//putchar(table[j][i]), putchar(table[j + 1][i]);
					//puts("");
				}
			}
		}
	}
	for(int i = 0; i < C; i++) {
		for(int j = 0; j < C; j++) {
			for(int k = 0; k < C; k++) {
				if (less[j][i] && less[i][k]) {
					less[j][k] = 1;
				}
			}
		}
	}
	for(int i = 0; i < C; i++) {
		if (less[i][i]) {
			puts("Impossible");
			exit(0);
		}
	}
	for(int i = 1; i < n; i++) {
		if (!done[i]) {
			puts("Impossible");
			exit(0);
		}
	}
	static int visit[N];
	fill(visit, visit + C, 0);
	//printf("%d\n", less['s' - 'a'][0]);
	for(int i = 0; i < C; i++) {
		for(int j = 0; j < C; j++) {
			if (!visit[j]) {
				bool flag = true;
				for(int k = 0; k < C; k++) {
					if (less[k][j]) {
						flag = false;
					}
				}
				if (flag) {
					putchar(j + 'a');
					for(int k = 0; k < C; k++) {
						less[j][k] = 0;
					}
					visit[j] = 1;
					break;
				}
			}
		}
	}
	puts(""); 
	return 0;
}