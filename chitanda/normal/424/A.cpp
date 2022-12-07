#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int n, tot[2], p, ret;
char s[500];

int main(){
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		if (s[i] == 'x') tot[0]++; else tot[1]++;
	if (tot[0] < tot[1]) ret = n / 2 - tot[0];
	else p = 1, ret = n / 2 - tot[1];
	printf("%d\n", ret);
	for(int i = 1; i <= n; i++){
		if (s[i] == 'x' && p == 1 && ret) { s[i] = 'X'; ret--; }
		else if (s[i] == 'X' && p == 0 && ret) { s[i] = 'x'; ret--; }
		printf("%c",s[i]);
	}
	return 0;
}