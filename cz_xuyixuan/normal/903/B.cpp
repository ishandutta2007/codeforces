#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int func(int s, int v) {
	if (s <= 0) return 0;
	else return (s - 1) / v + 1;
}
int main() {
	int h1, a1, h2, a2, c;
	read(h1), read(a1), read(c);
	read(h2), read(a2);
	c -= a2;
	int tmp = func((func(h2, a1) - 1) * a2 + 1 - h1, c);
	printf("%d\n", tmp + func(h2, a1));
	for (int i = 1; i <= tmp; i++)
		printf("HEAL\n");
	for (int i = 1; i <= func(h2, a1); i++)
		printf("STRIKE\n");
	return 0;
}