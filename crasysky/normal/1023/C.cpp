#include <iostream>
#include <cstdio>
using namespace std;
char s[1000006];
int st[1000006], belong[1000006];
int main(){
	int n, k;
	cin >> n >> k;
	scanf("%s", s);
	int tp = 0;
	for (int i = 0; i < n; ++ i)
		if (s[i] == '(')
			st[++ tp] = i;
		else
			belong[st[tp --]] = i;
	for (int i = 0; i < n; ++ i)
		if (belong[i] - i + 1 <= k){
			for (int j = i; j <= belong[i]; ++ j)
				printf("%c", s[j]);
			k -= belong[i] - i + 1;
			i = belong[i];
			if (k == 0)
				break;
		}
	return 0;
}