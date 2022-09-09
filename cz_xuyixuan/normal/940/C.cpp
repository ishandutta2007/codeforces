#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, k;
bool mark[MAXN];
char Min, Max, s[MAXN];
char succ(char x) {
	x++;
	while (!mark[x]) x++;
	return x;
}
int main() {
	read(n), read(k);
	scanf("\n%s", s + 1);
	mark[Min = Max = s[1]] = true;
	for (int i = 2; i <= n; i++) {
		Min = min(Min, s[i]);
		Max = max(Max, s[i]);
		mark[s[i]] = true;
	}
	if (k > n) {
		printf("%s", s + 1);
		for (int i = 1; i <= k - n; i++)
			printf("%c", Min);
		printf("\n");
		return 0;
	}
	for (int i = k; i >= 1; i--) {
		if (s[i] == Max) continue;
		s[i] = succ(s[i]);
		for (int j = i + 1; j <= n; j++)
			s[j] = Min;
		s[k + 1] = 0;
		printf("%s\n", s + 1);
		return 0;
	}
	return 0;
}