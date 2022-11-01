#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 100005, M = (N>>8)+5, K = 1<<8|3, C = 26;
int n, m, q, b[K], a[K<<1], nxt[N];
char s[N], t[N];
struct sam{
	char *s;
	int n, cnt, last, siz[K<<1], len[K<<1], fa[K<<1], ch[K<<1][C];
	inline void extend(int c){
		int p=last, np=++cnt;
		last=cnt, len[np]=len[p]+1;
		while(p && !ch[p][c]) ch[p][c]=np, p=fa[p];
		if(!p) fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1) fa[np]=q;
			else{
				int nq=++cnt;
				len[nq]=len[p]+1, memcpy(ch[nq], ch[q], C<<2);
				fa[nq]=fa[q], fa[np]=fa[q]=nq;
				while(ch[p][c]==q) ch[p][c]=nq, p=fa[p];
			}
		}
		++siz[np];
	}
	void build(){
		last=cnt=1, memset(siz, 0, sizeof siz), memset(ch, 0, sizeof ch);
		for(int i=0; i<n; ++i) extend(s[i]-'a');
		memset(b, 0, sizeof b);
		for(int i=1; i<=cnt; ++i) ++b[len[i]];
		for(int i=1; i<=n; ++i) b[i]+=b[i-1];
		for(int i=1; i<=cnt; ++i) a[b[len[i]]--]=i;
		for(int i=cnt; i>1; --i) siz[fa[a[i]]]+=siz[a[i]];
	}
	int query(){
		int p=1;
		for(int i=1; i<=m; ++i) p=ch[p][t[i]-'a'];
		return siz[p];
	}
} f[M];
inline int kmp(int l, int r){
	// printf("kmp: %d %d\n", l, r);
	int j=0, ans=0;
	for(int i=l; i<=r; ++i){
		while(j && t[j+1]!=s[i]) j=nxt[j];
		j+=(t[j+1]==s[i]);
		ans+=(j==m);
		// printf("[%d %d]\n", i, j);
	}
	return ans;
}
int main() {
	scanf("%s%d", s, &q), n=strlen(s);
	for(int i=0; i<=(n-1)>>8; ++i)
		f[i].s=s+(i<<8), f[i].n=min(1<<8, n-(i<<8)), f[i].build();
	while(q--){
		int opt, l, r;
		scanf("%d%d", &opt, &l), --l;
		if(opt==1) scanf("%c%c", s+l, s+l), f[l>>8].build();
		else{
			int ans=0;
			scanf("%d%s", &r, t+1), --r, m=strlen(t+1);
			int j=0;
			for(int i=2; i<=m; ++i){
				while(j && t[j+1]!=t[i]) j=nxt[j];
				nxt[i]=j+=(t[j+1]==t[i]);
			}
			if(m<=1<<8 && (l>>8)+1<r>>8){
				int L=l>>8, R=r>>8;
				// printf("L, R: %d %d\n", L, R);
				for(int i=L+1; i<R; ++i) ans+=f[i].query();
				ans+=kmp(l, ((L+1)<<8)+m-2)+kmp((R<<8)-m+1, r);
				for(int i=L+2; i<R; ++i) ans+=kmp((i<<8)-m+1, (i<<8)+m-2);
			}
			else ans=kmp(l, r);
			printf("%d\n", ans);
		}
	}
	return 0;
}