//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n,L,R;
char s[MAXN];

int main () {
	scanf("%d",&n);
	scanf("%s",s + 1);
	for(register int i = 1;i <= n; ++i)
		if(s[i] == 'L') L--;
		else R++;
	printf("%d\n",R - L + 1);
	return 0;
}