#include<bits/stdc++.h>
#define ll long long
const int N = 100005;
ll ans;
int n, m, cnt[N], nxt[N<<1];
char t[N], s[N<<1];
inline void kmp(){
	for(int i=2, j=0; i<=m; ++i){
		while(j && s[j+1]!=s[i]) j=nxt[j];
		nxt[i]=j+=(s[j+1]==s[i]);
		if(nxt[i]) ++cnt[i-nxt[i]];
	}
	for(int i=1; i<=m; ++i) cnt[i]+=cnt[i-1];
}
void exkmp(){
	for(int i=2, p=1; i<=n; ++i){
		for(nxt[i]=std::max(0, std::min(p+nxt[p]-i, nxt[i-p+1])); s[nxt[i]+1]==s[i+nxt[i]]; ++nxt[i]);
		if(i+nxt[i]>p+nxt[p]) p=i;
		if(i>m+2) ans-=cnt[nxt[i]];
	}
}
int main() {
	scanf("%s%s", t+1, s+1), n=strlen(t+1), m=strlen(s+1);
	ans=(ll)n*m, memcpy(s+m+2, t+1, n), s[m+1]='#', n+=m+1;
	kmp(), exkmp();
	return printf("%lld", ans), 0;
}