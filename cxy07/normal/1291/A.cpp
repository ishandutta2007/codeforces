//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3010;

int T,sum,len;
char s[MAXN];

int main () {
	cin >> T;
	while(T--) {
		sum = 0;
		cin >> len;
		cin >> s + 1;
		for(register int i = 1;i <= len; ++i)
			sum += s[i] - '0';
		while(len && (s[len] - '0') % 2 == 0) {
			sum -= s[len] - '0';
			len--;
		}
		if(!len) {puts("-1"); continue;}
		if((sum & 1) == 0) {
			for(register int i = 1;i <= len; ++i)
				printf("%c",s[i]);
			puts("");
			continue;
		}
		int L,flag = false;
		for(register int i = 1;i < len; ++i) {
			if((s[i] - '0') & 1) {
				flag = true,L = i + 1;
				while(L < len && s[L] == '0') L++;
				break;
			}
		}
		if(flag) {
			for(register int i = L;i <= len; ++i)
				printf("%c",s[i]);
			puts("");
		} else puts("-1");
	}
	return 0;
}