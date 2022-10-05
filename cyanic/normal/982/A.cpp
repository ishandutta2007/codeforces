#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 1005;
char s[maxn];
int n, res;

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	rep (i, 1, n-1)
		if (s[i] == '1' && s[i+1] == '1')
			return puts("No"), 0;
	rep (i, 2, n-1)
		if (s[i] == '0' && s[i-1] == '0' && s[i+1] == '0')
			return puts("No"), 0;
	if (n >= 2) {
		if (s[1] == '0' && s[2] == '0')
			return puts("No"), 0;
		if (s[n-1] == '0' && s[n] == '0')
			return puts("No"), 0;
	}
	else if (s[1] == '0')
		return puts("No"), 0;
	puts("Yes");	
	return 0;
}