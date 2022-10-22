//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 10;

int T,n;
int dp[MAXN];
int ans[MAXN],pos;
char s[MAXN];

inline int chk(int i) {
	if(i >= 2 && i + 2 <= n && s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') return i;
	if(i + 2 <= n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') return i + 1;
	if(i - 2 >= 1 && s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o') return i - 1;
	return 0;
}

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s + 1);
		pos = 0;
		n = strlen(s + 1);
		for(register int i = 1,tmp;i <= n; ++i) {
			tmp = chk(i);
			if(tmp) ans[++pos] = tmp;
		}
		printf("%d\n",pos);
		for(register int i = 1;i <= pos; ++i)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}