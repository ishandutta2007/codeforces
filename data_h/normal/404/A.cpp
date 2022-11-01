#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 333;

char map[N][N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	
	if (map[1][1] == map[2][1]) {
		printf("NO\n");
		return 0;
	}
	
	char deltaA = map[1][1], deltaB = map[2][1];
	bool flag = true;
	
	for(int i = 1; i <= n; i++) {
		if (map[i][i] != deltaA || map[i][n - i + 1] != deltaA) {
			flag = false;		
		}
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if (i == j || i == n - j + 1)
				continue;
			if (map[i][j] != deltaB)
				flag = false;
		}
	
	if (!flag) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}