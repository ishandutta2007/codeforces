#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
char s[200005];
int sta[200005],len,num[11];
inline void build(int o,int sta,int fr) {
	int i,j;
	memset (num,0,sizeof(num));
	for (int i=1; i<=o; i++) putchar(s[i]);
	for (int i=0; i<=9; i++) {
		if (sta&(1<<i)) num[i]++;
	}
	if (fr) {
		if (num[s[o+1]-1-'0']) {
			num[s[o+1]-1-'0']--;
		} else {
			fr--;
			num[s[o+1]-1-'0']++;
		}
		putchar(s[o+1]-1);
	} else {
		for (i=s[o+1]-1-'0'; i>=0; i--) {
			if (sta&(1<<i)) {
				putchar('0'+i);
				num[i]--;
				break;
			}
		}
	}
	for (i=o+2; i<=len; i++) {
		if (fr) {
			fr--;
			putchar('9');
			num[9]++;
			continue;
		}
		for (j=9; j>=0; j--) {
			if (num[j]) {
				putchar('0'+j);
				num[j]--;
				break;
			}
		}
	}
	puts("");
}
int main () {
	int T; scanf("%d",&T);
	while (T--) {
		scanf ("%s",s+1);
		len=strlen(s+1);
		int tag=1;
		for (int i=2; i<len; i++) {
			if (s[i]!='0') {
				tag=0;
				break;
			}
		}
		if (tag&&s[1]=='1'&&s[len]<='1') {
			for (int i=1; i<=len-2; i++) putchar('9');
			puts("");
			continue;
		}
		s[len]--;
		tag=0;
		if (s[len]<'0') {
			s[len]='9';
			tag=1;
		}
		for (int i=len-1; i>=1; i--) {
			if (!tag) break;
			s[i]--;
			tag=0;
			if (s[i]<'0') {
				s[i]='9';
				tag=1;
			}
		}
		for (int i=1; i<=len; i++) {
			sta[i]=sta[i-1]^(1<<(s[i]-'0'));
		}
		if (sta[len]==0) {
			for (int i=1; i<=len; i++) putchar(s[i]);
			puts("");
			continue;
		}
		for (int i=len-1; i>=0; i--) {
			if (i+__builtin_popcount(sta[i])<=len) {
				if (i+__builtin_popcount(sta[i])==len) {
					int lo=0;
					for (int j=0; j<=9; j++) {
						if (sta[i]&(1<<j)) {
							lo=j;
							break;
						}
					}
					if (lo<s[i+1]-'0') {
						build(i,sta[i],0);
						break;
					}
				} else {
					if (s[i+1]=='0') continue;
					build(i,sta[i],(len-i-__builtin_popcount(sta[i]))/2);
					break;
				}
			}
		}
	}
	return 0;
}