#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1111111;

int a[N], n, number[10];
char s[N];

int hash[5];
int num[5] = {0, 1, 6, 8, 9};
bool flag = false;

void dfs(int dep, int mo, int cur) {
	if (flag)
		return;
	if (dep == 5 && mo == 0) {
		printf("%d", cur);
		flag = true;
		return;
	}
	
	if (dep == 5)
		return;
	
	for(int i = 1; i <= 4; i++) {
		if (hash[i] == 0) {
			hash[i] = 1;
			dfs(dep + 1, (mo * 10 + num[i]) % 7, cur * 10 + num[i]);
			hash[i] = 0;
		}
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
		number[a[i]]++;
	}
	
	number[1]--;
	number[6]--;
	number[8]--;
	number[9]--;
	
	int m = 0, ss = 0;
	
	for(int i = 1; i <= 9; i++) {
		while(number[i]--) {
			printf("%d", i);
			ss = (ss * 10 + i) % 7;
		}
	}
	
	dfs(1, ss, 0);
	
	while(number[0]--) {
		printf("0");
	}
	puts("");
	return 0;
}