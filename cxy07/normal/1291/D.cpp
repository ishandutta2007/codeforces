//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n,q,L,R;
int sum[30][MAXN];
char s[MAXN];

int main () {
	cin >> s + 1;
	n = strlen(s + 1);
	for(register int i = 1;i <= n; ++i) {
		for(register int p = 0;p < 26; ++p)
			sum[p][i] = sum[p][i - 1];
		sum[s[i] - 'a'][i]++;
	}
	cin >> q;
	while(q--) {
		cin >> L >> R;
		if(s[L] != s[R] || L == R) {puts("Yes"); continue;}
		int cnt = 0;
		for(register int p = 0;p < 26; ++p)
			cnt += ((sum[p][R] - sum[p][L - 1]) > 0);
		if(cnt >= 3) puts("Yes");
		else puts("No");
	}
	return 0;
}