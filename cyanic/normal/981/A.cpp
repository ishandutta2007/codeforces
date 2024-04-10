#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 105;
char s[maxn];
int n, flag;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep (i, 1, n)
		if (s[i] != s[1]) {
			flag = 1; break;
		}
	if (!flag) puts("0");
	else {
		flag = 1;
		rep (i, 1, n)
			if (s[i] != s[n-i+1]) {
				flag = 0; break;
			}
		printf("%d\n", n-flag);
	}
	
	return 0;
}