// @betaveros :: generated with cpp2.hs
#include <cstdio>
using namespace std;
int n, m;
char s[108][108];
int get(int i, int j) {
	return i < n && j < m ? (s[i][j] == 'W' ? 1 : -1) : 0;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf(" ");
	for (int i = 0; i < n; ++i){
		fgets(s[i], 108, stdin);
	}
	int ops = 0;
	for (int i = n - 1; i >= 0; --i){
		for (int j = m - 1; j >= 0; --j){
			if (get(i, j) + get(i + 1, j + 1) != get(i, j + 1) + get(i + 1, j)){
				ops++;
			}
		}
	}
	printf("%d\n", ops);
}