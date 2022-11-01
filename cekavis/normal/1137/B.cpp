#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 500005;
int n, m, cnt[2], nxt[N];
char s[N], t[N];
inline void print(int c){
	if(!cnt[c]){
		while(cnt[0]) putchar('0'), --cnt[0];
		while(cnt[1]) putchar('1'), --cnt[1];
		exit(0);
	}
	putchar('0'+c), --cnt[c];
}
int main() {
	scanf("%s%s", s+1, t+1), n=strlen(s+1), m=strlen(t+1);
	for(int i=1; i<=n; ++i) ++cnt[s[i]-'0'];
	int j=0;
	for(int i=2; i<=m; ++i){
		while(j && t[j+1]!=t[i]) j=nxt[j];
		nxt[i]=j+=(t[j+1]==t[i]);
	}
	while(1) for(int i=1; i<=m-nxt[m]; ++i) print(t[i]-'0');
	return 0;
}