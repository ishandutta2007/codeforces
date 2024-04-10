#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char need[2000];
int hash[20000];
int pos[200];
char str[2000];

int check() {
	for(int i = 0; need[i]; i++) {
		if ((--hash[pos[need[i] - '0']]) < 0)
			return 0;
	}
	return 1;
}

int main() {
	scanf("%s", need);
	scanf("%s", str);
	for(int i = 0; i < 10; i++)
		pos[i] = i;
	pos[5] = 2;
	pos[9] = 6;
	for(int i = 0; str[i]; i++) {
		hash[pos[str[i] - '0']]++;
	}
	int ans = 0;
	while(check()) {
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}