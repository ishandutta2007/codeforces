#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 1000005;
int cnt[26], n;
char s[maxn];

int main() {
	scanf("%d", &n);
	if (n == 1)
		return puts("Yes"), 0;
	scanf("%s", s + 1);
	rep (i, 1, n)
		cnt[s[i]-'a']++;
	int flag = 0;
	rep (i, 0, 25)
		if (cnt[i] >= 2) {
			flag = 1; break;
		}
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}