#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 50, M = 1<<23, P = 998244353;
int n, cnt, cnt1, siz[N], id[N], e[N], fa[N], f[M], g[M];
bool TM[M];
char s[N][N];
inline int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void FWT(int *f){
	for(int i=1; i<1<<cnt; i<<=1) for(int j=0; j<1<<cnt; j+=i<<1) for(int k=j; k<j+i; ++k){
		int x=f[k], y=f[k+i];
		f[k]=x+y, f[k+i]=x-y;
	}
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%s", s[i]), fa[i]=i;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(s[i][j]=='A') fa[find(i)]=find(j);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(s[i][j]=='X' && find(i)==find(j)) return puts("-1"), 0;
	for(int i=0; i<n; ++i) ++siz[find(i)];
	for(int i=0; i<n; ++i){
		if(siz[i]>1) id[i]=cnt++;
		if(siz[i]==1) ++cnt1;
	}
	if(!cnt) return printf("%d\n", n-1), 0;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(s[i][j]=='X' && siz[fa[i]]>1 && siz[fa[j]]>1)
		e[id[fa[i]]]|=1<<id[fa[j]], e[id[fa[j]]]|=1<<id[fa[i]];
	for(int i=1; i<1<<cnt; ++i){
		f[i]=1;
		for(int j=0; j<cnt; ++j) if((i>>j&1) && (e[j]&i)) f[i]=0;
	}
	FWT(f);
	for(int i=0; i<1<<cnt; ++i) g[i]=f[i], TM[i]=TM[i>>1]^(i&1);
	for(int i=1; i<=cnt; ++i){
		ll sum=0;
		for(int j=0; j<1<<cnt; ++j) sum=(TM[j]?sum-f[j]:sum+f[j]);
		if(sum%P) return printf("%d\n", n+i-1), 0;
		for(int j=0; j<1<<cnt; ++j) f[j]=(ll)f[j]*g[j]%P;
	}
	return 0;
}