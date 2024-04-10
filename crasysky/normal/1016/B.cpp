#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
char str[maxn];
int s[maxn], s2[maxn], ss[maxn];
int n, m, q;
int aabs(int x){
	if (x >= 0)
		return x;
	return 0;
}
int main(){
	cin >> n >> m >> q;
	cin >> str;
	for (int i = n; i; -- i)
		s[i] = str[i - 1];
	cin >> str;
	for (int i = m; i; -- i)
		s2[i] = str[i - 1];
	for (int i = 1; i <= n - m + 1; ++ i){
		bool flag = false;
		for (int j = i; j <= i + m - 1; ++ j)
			if (s[j] != s2[j - i + 1]){
				flag = true;
				break;
			}
		ss[i] = ss[i - 1] + (! flag);
	}
	for (int i = max(n - m + 2, 1); i <= n; ++ i)
		ss[i] = ss[i - 1];
	while (q --){
		int l, r;
		scanf("%d %d", &l, &r);
		if (r >= m)
			printf("%d\n", aabs(ss[r - m + 1] - ss[l - 1]));
		else
			puts("0");
	}
}