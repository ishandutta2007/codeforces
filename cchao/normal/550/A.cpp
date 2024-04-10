#include <bits/stdc++.h>
using namespace std;

int main() {
	static char s[100010] = {};
	scanf("%s", s);
	char *aa = strstr(s, "AB");
	char *bb = strstr(s, "BA");

	puts((aa and strstr(aa + 2, "BA")) or (bb and strstr(bb + 2, "AB")) ? "YES" : "NO");

	return 0;
}