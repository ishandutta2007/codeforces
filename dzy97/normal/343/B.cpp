#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
char str[N];
int st[N], top;

int main(){
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for(int i = 1;i <= n;i ++){
		st[++ top] = str[i];
		while(top >= 2 && st[top] == st[top - 1]) top -= 2;
	}
	printf("%s\n", top ? "No" : "Yes");
	return 0;
}