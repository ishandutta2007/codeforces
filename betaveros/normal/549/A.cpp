// @betaveros :: generated with cpp2.hs
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
char s[58][58];
char store[8];
int main() {
	scanf("%d%d", &n, &m);
	scanf(" ");
	for (int i = 0; i < n; ++i){
		fgets(s[i], 58, stdin);
	}
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j < m - 1; ++j){
			store[0] = s[i][j];
			store[1] = s[i][j+1];
			store[2] = s[i+1][j];
			store[3] = s[i+1][j+1];
			sort(store, store + 4);
			if (!strcmp(store, "acef")){ cnt++; }
		}
	}
	printf("%d", cnt);
}